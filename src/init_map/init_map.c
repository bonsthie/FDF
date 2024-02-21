/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:23:08 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/20 15:29:40 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "fdf.h"
#include "init_map.h"
#include <stdlib.h>

t_position	*init_pos(t_map *map)
{
	t_position	*pos;

	pos = malloc(sizeof(t_position));
	if (!pos)
		return (NULL);
	pos->yaw = 359.3;
	pos->pitch = 253.4;
	pos->zoom_start = calculate_zoom_size(map->width, map->height);
	pos->zoom = pos->zoom_start * 3;
	pos->offset_y = 550.0;
	pos->offset_x = 1000.0;
	return (pos);
}

t_animation	*init_animation(void)
{
	t_animation	*anim;

	anim = malloc(sizeof(t_animation));
	if (!anim)
		return (NULL);
	anim->start = true;
	anim->rotate = true;
	anim->mouse_rotation = false;
	anim->mouse_translation = false;
	anim->translation = NULL;
	return (anim);
}

int	init_map(t_map *map)
{
	t_position	*pos;
	t_animation	*anim;
	int			biggest;

	pos = init_pos(map);
	anim = init_animation();
	map->color = malloc(map->height * map->width * sizeof(int));
	if (!pos || !anim || !map->color)
		return (1);
	standard_color(map);
	biggest = find_biggest(map->y, map->height * map->width);
	if (biggest < 10)
		map->y_scale = 1.0;
	else 
		map->y_scale = 20.0 / biggest;
	map->anim = anim;
	map->pos = pos;
	return (0);
}
