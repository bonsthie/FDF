/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_color_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:06:35 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 11:12:59 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "libft.h"

void	standard_color(t_map *map)
{
	ft_memcpy(map->color,
		map->standard_color,
		map->height * map->width * sizeof(int));
}
