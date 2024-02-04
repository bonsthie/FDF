/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/04 17:28:01 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "hook.h"
#include "parsing/parsing.h"
#include "print.h"
#include <math.h>
#include <stdio.h>

double	calculate_zoom_size(int new_columns, int new_rows)
{
	double	original_area;
	double	new_area;
	double	area_ratio;

	original_area = 19 * 12;
	new_area = new_columns * new_rows;
	area_ratio = original_area / new_area;
	return (20.0 * sqrt(area_ratio));
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = parsing_map(av[1]);
	if (!map)
		return (1);
	for (int i = 0; i < map->width * map->height; i++)
		printf("%d = %.1f \n", i, map->y[i]);
	map->mlx.image = NULL;
	map->mlx.connection = mlx_init();
	map->mlx.window = mlx_new_window(map->mlx.connection, WIDTH, HEIGHT, "FDF");
	map->mlx = map->mlx;
	map->yaw = 0.8;
	map->pitch = 0.7;
	map->zoom = calculate_zoom_size(map->width, map->height);
	map->offset_y = 0.0;
	map->offset_x = 0.0;
	map->mlx.image = mlx_new_image(map->mlx.connection, WIDTH, HEIGHT);
	print_map(map, map->mlx);
	mlx_on_event(map->mlx.connection, map->mlx.window, MLX_WINDOW_EVENT, window_hook,
		map->mlx.connection);
	mlx_on_event(map->mlx.connection, map->mlx.window, MLX_KEYDOWN, keyup_hook, map);
	mlx_on_event(map->mlx.connection, map->mlx.window, MLX_MOUSEDOWN, mousedown_hook,
		map);
	mlx_on_event(map->mlx.connection, map->mlx.window, MLX_MOUSEWHEEL, mousewheel, map);
	mlx_loop(map->mlx.connection);
	(void)av;
	return (ac);
	mlx_destroy_window(map->mlx.connection, map->mlx.window);
	mlx_destroy_display(map->mlx.connection);
}
