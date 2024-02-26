/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:48:44 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 10:52:47 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "print_bonus.h"

void	rotate(t_map *map)
{
	t_data	*mlx;

	mlx = map->mlx;
	map->pos->yaw -= 0.1;
	print_map(map, mlx);
}
