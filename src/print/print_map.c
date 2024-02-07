/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/07 09:11:31 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

__attribute__((always_inline))
inline void matrix_multiplication1x4(vec4d *matrix, vec4d vector, vec4d *result) {
	int i;
	vec4d product;
	double dot_product;

    *result = (vec4d){0, 0, 0, 0};
	i = 0;
    while (i < 4)
	{
		product = matrix[i] * vector;
        dot_product = product[0] + product[1] + product[2] + product[3];
        (*result)[i] = dot_product;
		i++;
    }
}


void	create_point2D(vec4d vect3, int *coord, vec4d *orientation, t_map map)
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
				plot_line(mlx, &coord[coord_index], &coord[coord_index + 2],
					0xE04062ff);
			if (i < map->height - 1)
			{
				index_below = coord_index + map->width * 2;
				plot_line(mlx, &coord[coord_index], &coord[index_below],
					0xffffffff);
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

	if (mlx->image != NULL)
		mlx_destroy_image(mlx->connection, mlx->image);
	mlx->image = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
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
	create_transformation_matrix(orientation, *map);
	while (i < size)
	{
		vect3[0] = i % map->width;
		vect3[1] = map->y[i];
		vect3[2] = (int)(i / map->width);
		vect3[3] = 1.0;
		create_point2D(vect3, &coord[co_i], orientation, *map);
		i++;
		co_i += 2;
	}
	print_map_screen(mlx, map, coord);
	free(coord);
}
