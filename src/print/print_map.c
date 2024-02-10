/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/10 21:03:57 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((always_inline)) void create_point2D(vec4d vect3, int *coord,
	vec4d *orientation, t_map map)
{
	vec4d	m_fov;

	matrix_multiplication1x4(orientation, vect3, &m_fov);

	coord[0] = (int)(m_fov[0] + map.offset_x);
	coord[1] = (int)(m_fov[1] + map.offset_y);
}

void	print_map_screen(t_data *mlx, t_map *map, int *coord)
{
	int	i;
	int	j;
	int	coord_index;
	int	color_index;
	int	index_below;

	i = 0;
	j = 0;
	coord_index = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			color_index = (i * map->width + j);
			coord_index = color_index * 2;
			if (j < map->width - 1)
				plot_line(mlx, &coord[coord_index], &coord[coord_index + 2],
					map->color[color_index]);
			if (i < map->height - 1)
			{
				index_below = coord_index + map->width * 2;
				color_index = color_index + map->width;
				plot_line(mlx, &coord[coord_index], &coord[index_below],
					map->color[color_index]);
			}
			j++;
		}
		i++;
	}
	mlx_clear_window(mlx->connection, mlx->window);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
}

void	print_map(t_map *map, t_data *mlx)
{
	int		*coord;
	int		co_i;
	int		i;
	int		size;
	vec4d	vect3;
	vec4d	orientation[4];

	if (mlx->image != NULL)
		mlx_destroy_image(mlx->connection, mlx->image);
	mlx->image = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	size = map->width * map->height;
	coord = malloc(2 * size * sizeof(int));
	if (!coord)
		return ;
	i = 0;
	co_i = 0;
	create_transformation_matrix(orientation, *map);
	while (i < size)
	{
		vect3[0] = i % map->width;
		vect3[1] = map->y[i] * map->y_scale;
		vect3[2] = (int)(i / map->width);
		vect3[3] = 1.0;
		create_point2D(vect3, &coord[co_i], orientation, *map);
		i++;
		co_i += 2;
	}
	print_map_screen(mlx, map, coord);
	free(coord);
}
