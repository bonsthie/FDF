/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/07 12:57:23 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "animation.h"
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
	return (50.0 * sqrt(area_ratio));
}

void mouse_translation(t_map *map)
{
	int x;
	int y;
	t_data *mlx;

	mlx = map->mlx;
	if (map->mouse_x != -1)
	{
		mlx_mouse_get_pos(mlx->connection, &x, &y);
		map->offset_x += (x - map->mouse_x);
		map->offset_y += (y - map->mouse_y);
		map->mouse_x = x;
		map->mouse_y = y;
	}
	mlx_mouse_get_pos(mlx->connection, &map->mouse_x, &map->mouse_y);
	refresh_screen(map->mlx);
	print_map(map, map->mlx);

}

void mouse_rotation(t_map *map)
{
	int x;
	int y;
	t_data *mlx;

	mlx = map->mlx;
	if (map->mouse_x != -1)
	{
		mlx_mouse_get_pos(mlx->connection, &x, &y);
		map->yaw += (x - map->mouse_x) * 0.3;
		map->pitch += (y - map->mouse_y) * 0.3;
		map->mouse_x = x;
		map->mouse_y = y;
	}
	mlx_mouse_get_pos(mlx->connection, &map->mouse_x, &map->mouse_y);
	refresh_screen(map->mlx);
	print_map(map, map->mlx);

}

int loop(void *content)
{
	t_map *map;
	t_data *mlx;

	map = content;
	mlx = map->mlx;
	if (map->start)
		apparition_animation(map);
	if (map->rotate)
		rotate(map);
	if (map->mouse_translation == true)
	{
		int x, y;
		mlx_mouse_get_pos(mlx->connection, &x, &y);
		printf("mouse [x == %d y == %d]\n", x, y);
		mouse_translation(map);
	}
	else if (map->mouse_rotation == true)
	{
		int x, y;
		mlx_mouse_get_pos(mlx->connection, &x, &y);
		printf("mouse [x == %d y == %d]\n", x, y);
		mouse_rotation(map);
	}
	return (0);
}


int	main(int ac, char **av)
{
	t_map	*map;
	t_data  mlx;

	map = parsing_map(av[1]);
	if (!map)
		return (1);
	for (int i = 0; i < map->width * map->height; i++)
		printf("%d = %.1f \n", i, map->y[i]);
	mlx.image = NULL;
	mlx.connection = mlx_init();
	mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "FDF");
	mlx.image = NULL;
	map->mlx = &mlx;
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
	mlx_on_event(mlx.connection, mlx.window, MLX_WINDOW_EVENT, window_hook,mlx.connection);
	mlx_on_event(mlx.connection, mlx.window, MLX_KEYDOWN, keyup_hook, map);
	mlx_on_event(mlx.connection, mlx.window, MLX_MOUSEDOWN, mousedown_hook,map);
	mlx_on_event(mlx.connection, mlx.window, MLX_MOUSEUP, mouseup_hook,map);
	mlx_on_event(mlx.connection, mlx.window, MLX_MOUSEWHEEL, mousewheel, map);

	mlx_loop_hook(mlx.connection, loop, map);
	mlx_loop(mlx.connection);
	mlx_destroy_image(mlx.connection, mlx.image);
	mlx_destroy_window(mlx.connection, mlx.window);
	mlx_destroy_display(mlx.connection);
	return (ac);
}
