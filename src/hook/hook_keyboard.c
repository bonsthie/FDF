/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:00:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/07 13:31:06 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>


int	keyup_hook(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == 79)
		map->offset_x += 10.1;
	else if (key == 80)
		map->offset_x -= 10.1;
	else if (key == 82)
		map->offset_y -= 10.1;
	else if (key == 81)
		map->offset_y += 10.1;
	else if (key == 26)
		map->pitch += 3.1;
	else if (key == 22)
		map->pitch -= 3.1;
	else if (key == 4)
		map->yaw += 3.1;
	else if (key == 7)
		map->yaw -= 3.1;
	else if (key == 6)
		map->rotate = !map->rotate;
	printf("%d\n", key);
	printf("x = %f  y = %f\n", map->pitch, map->yaw);
	print_map(map, map->mlx);
	return (0);
}



