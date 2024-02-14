/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apparition_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:12:20 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/13 12:18:04 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	apparition_animation(t_map *map)
{
	static double	yaw = 0.8;
	static double	pitch = 1.5;
	t_position		*pos;
	t_data			*mlx;

	mlx = map->mlx;
	pos = map->pos;
	print_map(map, mlx);
	if (pos->pitch > 210.0)
		pos->pitch -= pitch;
	if (pos->yaw > 322.0)
		pos->yaw -= yaw;
	if (pos->zoom > pos->zoom_start)
		pos->zoom -= pos->zoom_start * 0.05;
	if (pos->pitch <= 210.0 && pos->yaw <= 322.0
		&& pos->zoom <= pos->zoom_start)
		map->anim->start = false;
	if (yaw > 0.1)
	{
		pitch -= 0.015;
		yaw -= 0.010;
	}
}
