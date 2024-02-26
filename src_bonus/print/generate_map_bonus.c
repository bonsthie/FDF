/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 11:12:34 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "mlx.h"
#include "maths_bonus.h"
#include "print_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline void	create_point2d(t_vec4d vect4,
								int *coord,	
								t_vec4d *orientation,
								t_map map)
{
	t_vec4d	m_fov;

	matrix_multiplication1x4(orientation, vect4, &m_fov);
	coord[0] = (int)(m_fov[0] + map.pos->offset_x);
	coord[1] = (int)(m_fov[1] + map.pos->offset_y);
}

static void inline	create_point(t_map *map, int index, int *coord,
		t_vec4d *orientation)
{
	t_vec4d	vect4;

	vect4[0] = index % map->width;
	vect4[1] = map->y[index] * map->y_scale;
	vect4[2] = (int)(index / map->width);
	vect4[3] = 1.0;
	create_point2d(vect4, coord, orientation, *map);
}

void	print_map(t_map *map, t_data *mlx)
{
	int		*coord;
	int		co_i;
	int		i;
	int		size;
	t_vec4d	orientation[4];

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
		create_point(map, i, &coord[co_i], orientation);
		i++;
		co_i += 2;
	}
	print_map_screen(mlx, map, coord);
	free(coord);
}
