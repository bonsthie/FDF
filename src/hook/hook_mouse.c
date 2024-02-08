/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:31:23 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/08 19:02:00 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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

int	mousewheel(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 1)
	{
		map->zoom *= 1.07;
		print_map(map, map->mlx);
	}
	// Zoom out
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
