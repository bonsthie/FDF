/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:48:44 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/11 19:05:30 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"

void	rotate(t_map *map)
{
	t_data	*mlx;

	mlx = map->mlx;
	map->pos->yaw -= 0.1;
	print_map(map, mlx);
}
