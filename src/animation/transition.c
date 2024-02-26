/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:42:INCREMENT2 by babonnet          #+#    #+#     */
/*   Updated: 2024/02/21 21:13:37 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"

void	transition(t_map *map, t_position target)
{
	t_animation	*anim;

	anim = map->anim;
	map->pos->yaw = target.yaw;
	map->pos->pitch = target.pitch;
	anim->translation = NULL;
	anim->start = false;
	anim->rotate = false;
	print_map(map, map->mlx);
}
