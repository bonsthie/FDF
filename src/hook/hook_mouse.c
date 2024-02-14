/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:31:23 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/12 01:11:34 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"

int	mousedown_hook(int key, void *param)
{
	t_animation	*anim;
	t_map		*map;

	map = param;
	anim = map->anim;
	anim->rotate = false;
	anim->start = false;
	if (key == 1)
		anim->mouse_translation = true;
	else if (key == 3)
		anim->mouse_rotation = true;
	else
		return (1);
	print_map(map, map->mlx);
	return (0);
}

int	mouseup_hook(int key, void *param)
{
	t_map		*map;
	t_data		*mlx;
	t_animation	*anim;

	map = param;
	mlx = map->mlx;
	anim = map->anim;
	if (key == 1)
	{
		mlx->mouse_x = -1;
		mlx->mouse_y = -1;
		anim->mouse_translation = false;
	}
	else if (key == 3)
	{
		mlx->mouse_x = -1;
		mlx->mouse_y = -1;
		anim->mouse_rotation = false;
	}
	else
		return (1);
	return (0);
}

int	mousewheel_hook(int key, void *param)
{
	t_map		*map;
	t_position	*pos;

	map = param;
	pos = map->pos;
	map->anim->rotate = false;
	map->anim->start = false;
	if (key == 1)
		pos->zoom *= 1.07;
	else if (key == 2)
	{
		pos->zoom /= 1.03;
		if (pos->zoom < 0.3)
			pos->zoom = 0.3;
	}
	else
		return (1);
	print_map(map, map->mlx);
	return (0);
}

void	mouse_translation(t_map *map)
{
	int		x;
	int		y;
	t_data	*mlx;

	mlx = map->mlx;
	if (mlx->mouse_x != -1)
	{
		mlx_mouse_get_pos(mlx->connection, &x, &y);
		map->pos->offset_x += (x - mlx->mouse_x);
		map->pos->offset_y += (y - mlx->mouse_y);
		mlx->mouse_x = x;
		mlx->mouse_y = y;
	}
	mlx_mouse_get_pos(mlx->connection, &mlx->mouse_x, &mlx->mouse_y);
	mlx_clear_window(mlx->connection, mlx->window);
	print_map(map, map->mlx);
}

void	mouse_rotation(t_map *map)
{
	int		x;
	int		y;
	t_data	*mlx;

	mlx = map->mlx;
	if (mlx->mouse_x != -1)
	{
		mlx_mouse_get_pos(mlx->connection, &x, &y);
		map->pos->yaw += (x - mlx->mouse_x) * 0.3;
		map->pos->pitch += (y - mlx->mouse_y) * 0.3;
		mlx->mouse_x = x;
		mlx->mouse_y = y;
	}
	mlx_mouse_get_pos(mlx->connection, &mlx->mouse_x, &mlx->mouse_y);
	mlx_clear_window(mlx->connection, mlx->window);
	print_map(map, map->mlx);
}
