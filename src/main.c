/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/16 17:43:08 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "print.h"
#include "parsing/parsing.h"

#define LENGTH 720
#define WIDTH LENGTH * 9 / 16


#include <stdio.h>

int main(int ac, char **av)
{
	t_data		mlx;
	t_map	*map;

	map = parsing_map(av[1]);
	for (int i = 0; i < map->width * map->height; i++)
		printf("%d = %.1f \n", i, map->y[i]);
	mlx.image = NULL;
    mlx.connection = mlx_init();
    mlx.window = mlx_new_window(mlx.connection, LENGTH, WIDTH, "FDF");
	map->yaw = 0.8f;
	map->pitch = 0.7f;	
	map->zoom = 0.2f;
	map->offset_x = 0.0;
	map->offset_y = 0.0;
	print_map(map, mlx);
    mlx_loop(mlx.connection);
	(void)av;
    return (ac);
}
