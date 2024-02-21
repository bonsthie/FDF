/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/17 17:52:24 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"

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
