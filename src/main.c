/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/16 01:22:40 by bbonnet          ###   ########.fr       */
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
	print_map(map, mlx);
    mlx_loop(mlx.connection);
	(void)av;
    return (ac);
}
