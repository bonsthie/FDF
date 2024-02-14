/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/14 16:19:35 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "maths.h"
#include "print.h"
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

static inline void	print_2line(t_map *map, int *coord, int i, int j)
{
	int	coord_index;
	int	color_index;
	int	index_below;

	color_index = (i * map->width + j);
	coord_index = color_index * 2;
	if (j < map->width - 1)
		plot_line(map->mlx, &coord[coord_index], &coord[coord_index + 2],
			map->color[color_index]);
	if (i < map->height - 1)
	{
		index_below = coord_index + map->width * 2;
		color_index = color_index + map->width;
		plot_line(map->mlx, &coord[coord_index], &coord[index_below],
			map->color[color_index]);
	}
}

void	print_map_screen(t_data *mlx, t_map *map, int *coord)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			print_2line(map, coord, i, j);
			j++;
		}
		i++;
	}
	mlx_clear_window(mlx->connection, mlx->window);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
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

#include <stdio.h>
#include <time.h>

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
	clock_t start, end;
	start = clock();
	while (i < size)
	{
		create_point(map, i, &coord[co_i], orientation);
		i++;
		co_i += 2;
	}
	end = clock();
	printf("time matrix = %ld\n", 1000000 / (end - start));
	start = clock();
	print_map_screen(mlx, map, coord);
	end = clock();
	printf("time render = %ld\n", 1000000 / (end - start));
	free(coord);
}
