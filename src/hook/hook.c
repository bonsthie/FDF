/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:00:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/07 12:55:23 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

int	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
	return (0);
}

int	keyup_hook(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 79)
		map->offset_x += 10.1;
	else if (key == 80)
		map->offset_x -= 10.1;
	else if (key == 82)
		map->offset_y -= 10.1;
	else if (key == 81)
		map->offset_y += 10.1;
	else if (key == 26)
		map->pitch += 3.1;
	else if (key == 22)
		map->pitch -= 3.1;
	else if (key == 4)
		map->yaw += 3.1;
	else if (key == 7)
		map->yaw -= 3.1;
	else if (key == 6)
		map->rotate = !map->rotate;
	printf("%d\n", key);
	printf("x = %f  y = %f\n", map->pitch, map->yaw);
	print_map(map, map->mlx);
	return (0);
}


int	mousedown_hook(int key, void *param)
{
	t_map	*map;

	printf("input %d\n", key);
	map = param;
	if (key == 1)
	{
		map->mouse_translation = true;
		write(2, "1\n", 2);
	}
	else if (key == 3)
		map->mouse_rotation = true;
	else
		return (1);
	print_map(map, map->mlx);
	return (0);
}

int	mouseup_hook(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 1)
	{
		map->mouse_x = -1;
		map->mouse_y = -1;
		map->mouse_translation = false;
	}
	else if (key == 3)
	{
		map->mouse_x = -1;
		map->mouse_y = -1;
		map->mouse_rotation = false;
	}
	else 
		return (1);
	return (0);
}

int	mousewheel(int key, void *param)
{
	t_map	*map;
	int		x;
	int		y;

	map = param;
	if (key == 1)
		map->zoom *= 1.03;
	// Zoom out
	else if (key == 2)
	{
		map->zoom /= 1.03;
		if (map->zoom < 0.3)
			map->zoom = 0.3;
	}
	else
		return (1);
	mlx_mouse_get_pos(map->mlx->connection, &x, &y);
	//map->offset_x += map->offset_x - x * map->zoom;
	//map->offset_y += map->offset_y - y * map->zoom;
	printf("zooom ======= %.2f\n", map->zoom);
	refresh_screen(map->mlx);
	print_map(map, map->mlx);
	return (0);
}
