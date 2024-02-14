/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:42:INCREMENT2 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/11 23:44:40 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"

void	transition(t_map *map, t_position end_position)
{
	t_position	*start_pos;
	static int	pitch_way = INCREMENT;
	static int	yaw_way = INCREMENT;

	start_pos = map->pos;
	if (start_pos->yaw < end_position.yaw)
		yaw_way = -INCREMENT;
	if (start_pos->pitch < end_position.pitch)
		pitch_way = -INCREMENT;
	if (pitch_way == INCREMENT && start_pos->pitch > end_position.pitch)
		start_pos->pitch -= pitch_way;
	else if (start_pos->pitch < end_position.pitch)
		start_pos->pitch -= pitch_way;
	if (yaw_way == INCREMENT && start_pos->yaw > end_position.yaw)
		start_pos->yaw -= yaw_way;
	else if (start_pos->yaw < end_position.yaw)
		start_pos->yaw -= yaw_way;
	if (yaw_way == INCREMENT)
	{
		if (pitch_way == INCREMENT)
		{
			if (start_pos->pitch <= end_position.pitch
				&& start_pos->yaw <= end_position.yaw)
				map->anim->translation = NULL;
		}
		else
		{
			if (start_pos->pitch >= end_position.pitch
				&& start_pos->yaw <= end_position.yaw)
				map->anim->translation = NULL;
		}
	}
	else
	{
		if (pitch_way == INCREMENT)
		{
			if (start_pos->pitch <= end_position.pitch
				&& start_pos->yaw >= end_position.yaw)
				map->anim->translation = NULL;
		}
		else
		{
			if (start_pos->pitch >= end_position.pitch
				&& start_pos->yaw >= end_position.yaw)
				map->anim->translation = NULL;
		}
	}
	print_map(map, map->mlx);
	if (map->anim->translation == NULL)
	{
		pitch_way = INCREMENT;
		yaw_way = INCREMENT;
	}
}
