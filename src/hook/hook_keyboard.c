/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:00:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/10 20:51:48 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <stdio.h>


static void offset_input(int key, void *param)
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

}

int	keyup_hook(int key, void *param)
{
	t_map	*map;

	map = param;
	map->rotate = false;
	map->start = false;
	if (key == 41)
		mlx_loop_end(map->mlx->connection);
	else if (key >= 79 && key <= 82)
		offset_input(key, param);
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
	else if (key == 18)
		map->y_scale += 0.03;
	else if (key == 15)
		map->y_scale -= 0.03;
	else if (key == 19)
		map->zoom += 100;
	printf("%d\n", key);
	print_map(map, map->mlx);
	return (0);
}
