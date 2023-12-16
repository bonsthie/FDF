/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/16 17:01:11 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define WIDTH 720
#define HEIGHT WIDTH * 9 / 16

#include <math.h>
#include <stdlib.h>

void	matrix_multiplication4x4(float result[16], const float a[16],
		const float b[16])
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			result[y * 4 + x] = 0; 
			for (int k = 0; k < 4; k++)
			{
				result[y * 4 + x] += a[y * 4 + k] * b[k * 4 + x];
			}
		}
	}
}

float	*create_transformation_matrix(float pitch, float yaw, float zoom)
{
	float	*transformation;
	float	tempMatrix[16];
	float	pitchMatrix[16] = {1, 0, 0, 0, 0, cos(pitch), -sin(pitch), 0, 0,
			sin(pitch), cos(pitch), 0, 0, 0, 0, 1};
	float	yawMatrix[16] = {cos(yaw), 0, sin(yaw), 0, 0, 1, 0, 0, -sin(yaw), 0,
			cos(yaw), 0, 0, 0, 0, 1};
	float	scaleMatrix[16] = {zoom, 0, 0, 0, 0, zoom, 0, 0, 0, 0, zoom, 0, 0,
			0, 0, 1};

	transformation = malloc(16 * sizeof(float));
	if (!transformation)
	{
		return (NULL);
	}
	matrix_multiplication4x4(tempMatrix, pitchMatrix, yawMatrix);
	matrix_multiplication4x4(transformation, tempMatrix, scaleMatrix);
	return (transformation);
}

float	*matrix_multiplication1x4(float *v, float *transformation) // opti
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
	return (matrix);
}

float	*fov(void)
{
	static float	matrix[16] = {0.0};
	float			aspect_ratio;
	float			fov_radians;
	float			fov;

	float fov_degrees = 45.0; // Typical field of view angle
	aspect_ratio = (float)WIDTH / (float)HEIGHT;
	float near = 0.1;   // Should be greater than 0
	float far = 1000.0; // Based on the scene's depth
	fov_radians = fov_degrees * M_PI / 180.0;
	fov = 1.0 / tan(fov_radians / 2.0);
	// Reset matrix to zero before initializing
	for (int i = 0; i < 16; ++i)
	{
		matrix[i] = 0.0f;
	}
	matrix[0] = fov / aspect_ratio;
	matrix[5] = fov;
	matrix[10] = -(far + near) / (far - near);
	matrix[14] = -(2.0 * far * near) / (far - near);
	matrix[11] = 1.0;
	matrix[15] = 0.0;
	return (matrix);
}

void	create_point2D(float *vect3, int *coord, float *orientation)
{
	float	*m_fov;

	m_fov = matrix_multiplication1x4(vect3, orientation);
	// float *m_fov = matrix_multiplication1x4(m_orientation, fov());
	printf("after matrix x = %.1f y = %.1f z = %.1f w == %.1f\n", vect3[0],
		vect3[1], vect3[2], vect3[3]);
	coord[0] = ((m_fov[0] / m_fov[3]) + 1) * (WIDTH / 2.0);
	coord[1] = ((m_fov[1] / m_fov[3]) + 1) * ((float)HEIGHT / 2.0);
}

void	print_map_screen(t_data data, t_map *map, int *coord)
{
	int	i;
	int	j;
	int	coord_index;
	int	index_below;

	i = 0;
	j = 0;
	coord_index = 0;
	if (data.image != NULL)
		mlx_destroy_image(data.connection, data.image);
	data.image = mlx_new_image(data.connection, WIDTH, HEIGHT);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			coord_index = (i * map->width + j) * 2;
			if (j < map->width - 1)
				plot_line(data, &coord[coord_index], &coord[coord_index + 2],
					0xE04062ff);
			if (i < map->height - 1)
			{
				index_below = coord_index + map->width * 2;
				plot_line(data, &coord[coord_index], &coord[index_below],
					0xffffffff);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data.connection, data.window, data.image, 0, 0);
}

void	print_map(t_map *map, t_data data)
{
	int		*coord;
	int		co_i;
	int		i;
	int		size;
	float	vect3[4];
	float	*orientation;

	size = map->width * map->height;
	i = 0;
	coord = malloc(2 * size * sizeof(int));
	co_i = 0;
	orientation = create_transformation_matrix(map->pitch, map->yaw, map->zoom);
	while (i < size)
	{
		vect3[0] = i % map->width;
		vect3[1] = map->y[i];
		vect3[2] = (int)(i / map->width);
		vect3[3] = 1.0f;
		printf("before :x = %.1f y = %.1f z = %.1f w == %.1f\n", vect3[0], vect3[1], vect3[2], vect3[3]);
		create_point2D(vect3, &coord[co_i], orientation);
		i++;
		co_i += 2;
	}
	free(orientation);
	print_map_screen(data, map, coord);
}
