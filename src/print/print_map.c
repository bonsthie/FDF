/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/04 22:34:01 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdlib.h>

typedef double vec4d __attribute__((vector_size(4 * sizeof(double))));

__attribute__((always_inline))
void matrix_multiplication4x4(vec4d result[4], const vec4d a[4], vec4d b[4]) {
	int i;
	int j;
	vec4d temp;
	vec4d replicated;

	i = 0;
    while (i < 4) {
        temp = (vec4d){0, 0, 0, 0};
		j = 0;
        while (j < 4) {
            replicated = (vec4d){a[i][j], a[i][j], a[i][j], a[i][j]};
            temp += replicated * b[j];
			j++;
        }
        result[i] = temp;
		i++;
    }
}

void create_transformation_matrix(vec4d *transformation, double pitch, double yaw, double zoom, double offset_x, double offset_y) {
    pitch *= (M_PI / 180.0); 
    yaw *= (M_PI / 180.0);
    double cosPitch = cos(pitch), sinPitch = sin(pitch);
    double cosYaw = cos(yaw), sinYaw = sin(yaw);

    vec4d pitchMatrix[4] = {
		{ 1, 0, 0, -offset_x, },
        { 0, cosPitch, -sinPitch, -offset_y, },
        { 0, sinPitch, cosPitch, 0,  },
        { 0, 0, 0, 1 }
    };
    vec4d yawMatrix[4] = {
		{cosYaw, 0, sinYaw, -offset_x},
		{ 0, 1, 0, -offset_y,},
		{-sinYaw, 0, cosYaw, 0},
		{0, 0, 0, 1}
    };
    vec4d scaleMatrix[4] = {
		{ zoom, 0, 0, offset_x },
        { 0, zoom, 0, offset_y },
        { 0, 0, zoom, 0 },
        { 0, 0, 0, 1 }
    };

    vec4d tempMatrix[4] = {
		{ 0 , 0 , 0, 0 },
		{ 0 , 0 , 0, 0 },
		{ 0 , 0 , 0, 0 },
		{ 0 , 0 , 0, 0 }
	};
    matrix_multiplication4x4(tempMatrix, pitchMatrix, yawMatrix);
    matrix_multiplication4x4(transformation, tempMatrix, scaleMatrix);
}

__attribute__((always_inline))
void matrix_multiplication1x4(vec4d *matrix, vec4d vector, vec4d *result) {
    // Initialize the result vector to zero
    *result = (vec4d){0, 0, 0, 0};

    for (int i = 0; i < 4; ++i) {
        vec4d product = matrix[i] * vector;
        double dot_product = product[0] + product[1] + product[2] + product[3];
        (*result)[i] = dot_product;
    }
}


void	create_point2D(vec4d vect3, int *coord, vec4d *orientation)
{
	vec4d	m_fov;

	matrix_multiplication1x4(orientation, vect3, &m_fov);
	coord[0] = (int)(m_fov[0] + 1);
	coord[1] = (int)(m_fov[1] + 1);
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
	vec4d	vect3;

	size = map->width * map->height;
	coord = malloc(2 * size * sizeof(int));
	if (!coord)
		return ;
	i = 0;
	co_i = 0;
    vec4d orientation[4] = {
		{ 0 , 0 , 0, 0 },
		{ 0 , 0 , 0, 0 },
		{ 0 , 0 , 0, 0 },
		{ 0 , 0 , 0, 0 }
	};
	create_transformation_matrix(orientation, map->pitch, map->yaw, map->zoom,
			map->offset_x, map->offset_y);
	while (i < size)
	{
		vect3[0] = i % map->width;
		vect3[1] = map->y[i];
		vect3[2] = (int)(i / map->width);
		vect3[3] = 1.0;
		create_point2D(vect3, &coord[co_i], orientation);
		i++;
		co_i += 2;
	}
	print_map_screen(data, map, coord);
	free(coord);
}
