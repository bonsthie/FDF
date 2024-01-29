/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:29:14 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/29 11:35:27 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"
#include "fdf.h"
#include "hook.h"

int	loop(void *content)
{
	t_map	*map;

	map = content;
	if (map->start)
		apparition_animation(map);
	else if (map->rotate)
		rotate(map);
	else if (map->mouse_translation == true)
		mouse_translation(map);
	else if (map->mouse_rotation == true)
		mouse_rotation(map);
	return (0);
}
