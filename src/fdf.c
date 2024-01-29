/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/29 11:37:39 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "hook.h"
#include "parsing/parsing.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double	calculate_zoom_size(int new_columns, int new_rows)
{
	double	original_area;
	double	new_area;
	double	area_ratio;

	original_area = 19 * 12;
	new_area = new_columns * new_rows;
	area_ratio = original_area / new_area;
	return (50.0 * sqrt(area_ratio));
}

void init_map(t_map *map)
{
	map->yaw = 359.3;
	map->pitch = 253.4;
	map->zoom_start = calculate_zoom_size(map->width, map->height);
	map->zoom = map->zoom_start * 3;
	map->offset_y = 300.0;
	map->offset_x = 550.0;
	map->mouse_x = -1;
	map->mouse_y = -1;
	map->start = true;
	map->rotate = true;
	map->mouse_rotation = false;
	map->mouse_translation = false;
}

void destroy(t_map *map)
{
	t_data mlx;

	mlx = *map->mlx;
	free(map->y);
	free(map->color);
	mlx_destroy_image(mlx.connection, mlx.image);
	mlx_destroy_window(mlx.connection, mlx.window);
	mlx_destroy_display(mlx.connection);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_data	mlx;

	map = parsing_map(av[1]);
	if (!map)
		return (1);
	mlx.connection = mlx_init();
	mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "FDF");
	mlx.image = NULL;
	map->mlx = &mlx;
	init_map(map);
	for (int i = 0; i < map->width * map->height; i++)
		printf("%d = %.1f \n", i, map->y[i]);
	hook(map);
	mlx_loop_hook(mlx.connection, loop, map);
	mlx_loop(mlx.connection);
	destroy(map);
	return (ac);
}
