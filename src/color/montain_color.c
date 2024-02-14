/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   montain_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 23:53:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/12 01:05:01 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	montain_color(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->width * map->height)
	{
		if (map->y[i] <= 0)
			map->color[i] = 0xFF001db0;
		else if (map->y[i] <= 200)
			map->color[i] = 0xFF014503;
		else if (map->y[i] >= 450)
			map->color[i] = 0xFFbfbebd;
		else
			map->color[i] = 0xFF361d01;
		i++;
	}
}
