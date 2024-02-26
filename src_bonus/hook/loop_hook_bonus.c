/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:29:14 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 10:52:48 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation_bonus.h"
#include "fdf_bonus.h"
#include "hook_bonus.h"

static void	stay_in_360(t_position *pos)
{
	if (pos->pitch > 360)
		pos->pitch -= 360;
	if (pos->yaw > 360)
		pos->yaw -= 360;
	if (pos->pitch < 0)
		pos->pitch = 360 + pos->pitch;
	if (pos->yaw < 0)
		pos->yaw = 360 + pos->yaw;
}

int	loop(void *content)
{
	t_map		*map;
	t_animation	*anim;

	map = content;
	anim = map->anim;
	if (anim->start)
		apparition_animation(map);
	else if (anim->rotate)
		rotate(map);
	else if (anim->mouse_translation == true)
		mouse_translation(map);
	else if (anim->mouse_rotation == true)
		mouse_rotation(map);
	if (anim->translation)
		transition(map, *anim->translation);
	stay_in_360(map->pos);
	return (0);
}
