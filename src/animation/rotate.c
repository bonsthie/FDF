/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:48:44 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/29 11:39:39 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"

void	rotate(t_map *map)
{
	t_data	*mlx;

	mlx = map->mlx;
	map->yaw -= 0.1;
	print_map(map, mlx);
}
