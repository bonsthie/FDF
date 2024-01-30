/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/30 19:47:43 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	matrix_multiplication4x4(double result[16], const double a[16],
		const double b[16])
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

double	*create_transformation_matrix(double pitch, double yaw, double zoom,
		double offset_x, double offset_y)
{
	double	*transformation;
	double	tempMatrix[16];
	double	*pitchMatrix;
	double	*yawMatrix;
	double	*scaleMatrix;

	pitchMatrix = (double[]){1, 0, 0, 0, 0, cos(pitch), -sin(pitch), 0, 0,
		sin(pitch), cos(pitch), 0, 0, 0, 0, 1};
	yawMatrix = (double[]){cos(yaw), 0, sin(yaw), 0, 0, 1, 0, 0, -sin(yaw), 0,
		cos(yaw), 0, 0, 0, 0, 1};
	scaleMatrix = (double[]){zoom, 0, 0, offset_x,
							0, zoom, 0, offset_y,
							0, 0, zoom, 0,
							0, 0, 0, 1};
	pitch = fmod(pitch, 360);
	yaw = fmod(yaw, 360);
	transformation = malloc(16 * sizeof(double));
	if (!transformation)
	{
		return (NULL);
	}
	matrix_multiplication4x4(tempMatrix, pitchMatrix, yawMatrix);
	matrix_multiplication4x4(transformation, tempMatrix, scaleMatrix);
	return (transformation);
}

double	*matrix_multiplication1x4(double *v, double *transformation) // opti
{
	double *matrix;
	int i;

	i = 0;
	matrix = malloc(4 * sizeof(double));
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

void	create_point2D(double *vect3, int *coord, double *orientation)
{
	double	*m_fov;

	m_fov = matrix_multiplication1x4(vect3, orientation);
	coord[0] = ((m_fov[0] / m_fov[3]) + 1) * (WIDTH / 2.0);
	coord[1] = ((m_fov[1] / m_fov[3]) + 1) * ((double)HEIGHT / 2.0);
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
	// data.image = mlx_new_image(data.connection, WIDTH, HEIGHT);
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
	double	vect3[4];
	double	*orientation;

	size = map->width * map->height;
	i = 0;
	coord = malloc(2 * size * sizeof(int));
	co_i = 0;
	orientation = create_transformation_matrix(map->pitch, map->yaw, map->zoom,
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
	free(orientation);
	print_map_screen(data, map, coord);
}
