/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/16 01:21:34 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdlib.h>


#include <stdio.h>
#define WIDTH 720
#define HEIGHT WIDTH * 9 / 16

float *matrix_multiplication4x4(float *a, float *b) {
    float *result = malloc(16 * sizeof(float));  // Allocate memory for a 4x4 matrix
    if (!result) {
        return (NULL);
    }

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            result[y * 4 + x] = 0;  // Initialize to 0
            for (int k = 0; k < 4; k++) {
                result[y * 4 + x] += a[y * 4 + k] * b[k * 4 + x];
            }
        }
    }

    return (result);
}

float *matrix_multiplication1x4(float *v, float *transformation) //opti
{
	float *matrix;
	int i;

	i = 0;
	matrix = malloc(4 * sizeof(float));
	if (!matrix)
		return (NULL);
	while (i < 4)
		matrix[i++] = 0;
	i = 0;
	while (i < 16)
	{
		matrix[i / 4] += transformation[i] * v[i % 4];
		i++;		
	}
	free(transformation);
	return (matrix);
}

float *orientation(float pitch, float yaw)
{
	// Rotation matrix for pitch
	float pitchMatrix[16] = {
		1, 0, 0, 0,
		0, cos(pitch), -sin(pitch), 0,
		0, sin(pitch), cos(pitch), 0,
		0, 0, 0, 1
	};

	// Rotation matrix for yaw
	float yawMatrix[16] = {
		cos(yaw), 0, sin(yaw), 0,
		0, 1, 0, 0,
		-sin(yaw), 0, cos(yaw), 0,
		0, 0, 0, 1
	};
	return (matrix_multiplication4x4(pitchMatrix, yawMatrix));
}


float *fov(void) {
    static float matrix[16] = {0.0};
    float fov_degrees = 45.0; // Typical field of view angle
    float aspect_ratio = (float)WIDTH / (float)HEIGHT;
    float near = 0.1; // Should be greater than 0
    float far = 1000.0; // Based on the scene's depth

    float fov_radians = fov_degrees * M_PI / 180.0;
    float fov = 1.0 / tan(fov_radians / 2.0);

    // Reset matrix to zero before initializing
    for (int i = 0; i < 16; ++i) {
        matrix[i] = 0.0f;
	}

    matrix[0] = fov / aspect_ratio;
    matrix[5] = fov;
    matrix[10] = -(far + near) / (far - near);
    matrix[14] = -(2.0 * far * near) / (far - near);
    matrix[11] = 1.0;
    matrix[15] = 0.0;

    return matrix;
}




void create_point2D(float *vect3, int *coord, float pitch, float yaw)
{
	float *m_fov = matrix_multiplication1x4(vect3, orientation(pitch, yaw));
	float zoom = 0.2;
	float offset = 100;
	//float *m_fov = matrix_multiplication1x4(m_orientation, fov());
    printf("after matrix x = %.1f y = %.1f z = %.1f w == %.1f\n", vect3[0], vect3[1], vect3[2], vect3[3]);

	coord[0] = ((m_fov[0]/ m_fov[3]) + 1) * (WIDTH / 2.0) * zoom + offset;
	coord[1] = ((m_fov[1] / m_fov[3]) + 1) * ((float)HEIGHT / 2.0) * zoom + offset;
}


void print_map_screen(t_data data, t_map *map, int *coord)
{
    int i = 0;
    int j = 0;
    int coord_index = 0;

    if (data.image != NULL)
        mlx_destroy_image(data.connection, data.image);
    data.image = mlx_new_image(data.connection, WIDTH, HEIGHT);

    while (i < map->height) {
        j = 0;
        while (j < map->width) {
            coord_index = (i * map->width + j) * 2;

            if (j < map->width - 1)
                plot_line(data, &coord[coord_index], &coord[coord_index + 2], 0xE04062ff);
            if (i < map->height - 1) {
                int index_below = coord_index + map->width * 2;
                plot_line(data, &coord[coord_index], &coord[index_below], 0xffffffff);
            }

            j++;
        }
        i++;
    }

    mlx_put_image_to_window(data.connection, data.window, data.image, 0, 0);
}



void print_map(t_map *map, t_data data)
{
	int *coord;
	int		co_i;
	int i;
	int size;
	float vect3[4];

	size = map->width * map->height;
	i = 0;
	coord = malloc(2 * size * sizeof(int));
	co_i = 0;
	while (i < size)
	{
		vect3[0] = i % map->width;
		vect3[1] = map->y[i];
		vect3[2] = (int)(i / map->width);
		vect3[3] = 1.0f;
        printf("before :x = %.1f y = %.1f z = %.1f w == %.1f\n", vect3[0], vect3[1], vect3[2], vect3[3]);
		create_point2D(vect3, &coord[co_i], map->pitch, map->yaw);
		i++;
		co_i += 2;
	}
	print_map_screen(data, map, coord);
}
