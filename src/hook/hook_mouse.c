/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:31:23 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/29 11:35:14 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"

int	mousedown_hook(int key, void *param)
{
	t_map	*map;

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

int	mousewheel_hook(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 1)
	{
		map->zoom *= 1.07;
		print_map(map, map->mlx);
	}
	else if (key == 2)
	{
		map->zoom /= 1.03;
		if (map->zoom < 0.3)
			map->zoom = 0.3;
		print_map(map, map->mlx);
	}
	else
		return (1);
	return (0);
}

void	mouse_translation(t_map *map)
{
	int		x;
	int		y;
	t_data	*mlx;

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

void	mouse_rotation(t_map *map)
{
	int		x;
	int		y;
	t_data	*mlx;

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
