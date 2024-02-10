/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apparition_animation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:12:20 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/10 00:29:56 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <math.h>

void	apparition_animation(t_map *map)
{
	static float	yaw = 0.8;
	static float	pitch = 1.5;
	t_data			*mlx;

	mlx = map->mlx;
	print_map(map, mlx);
	if (map->pitch > 210.0)
		map->pitch -= pitch;
	if (map->yaw > 322.0)
		map->yaw -= yaw;
	if (map->zoom > map->zoom_start)
		map->zoom -= map->zoom_start * 0.05;
	if (map->pitch <= 210.0 && map->yaw <= 322.0
		&& map->zoom <= map->zoom_start)
		map->start = false;
	if (yaw > 0.1)
	{
		pitch -= 0.015;
		yaw -= 0.010;
	}
}
