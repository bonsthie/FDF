/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   montain_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:53:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 10:52:47 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	montain_color(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->width * map->height)
	{
		if (map->y[i] <= -200)
			map->color[i] = 0xFF192586;
		if (map->y[i] <= -100)
			map->color[i] = 0xFF27379B;
		else if (map->y[i] <= -50)
			map->color[i] = 0xFF2F41A7;
		else if (map->y[i] <= -10)
			map->color[i] = 0xFF384BB4;
		else if (map->y[i] <= 0)
			map->color[i] = 0xFF3F53BE;
		else if (map->y[i] <= 200)
			map->color[i] = 0xFF014503;
		else if (map->y[i] >= 450)
			map->color[i] = 0xFFbfbebd;
		else
			map->color[i] = 0xFF361d01;
		i++;
	}
}
