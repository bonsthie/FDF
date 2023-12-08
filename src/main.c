/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/08 08:15:02 by babonnet         ###   ########.fr       */
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
    void    *mlx_connection;
    void    *mlx_window;
	t_vertex	*map;

	map = parsing_map(av[1]);
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, LENGTH, WIDTH, "test");
	print_map(map, mlx_connection, mlx_window);
	//t_vect2 v1, v2, v3, v4;

	//v1.x = 49;
	//v1.z = 120;

	//v2.x = 124;
	//v2.z = 120;

	//v3.x = 20;
	//v3.z = 49;

	//v4.x = 90;
	//v4.z = 49;

	//plotLine(mlx_connection, mlx_window, v1, v2, 0xE04062);
	//plotLine(mlx_connection, mlx_window, v1, v3, 0x80BC2B);
	//plotLine(mlx_connection, mlx_window, v3, v4, 0x8470FF);
	//plotLine(mlx_connection, mlx_window, v4, v2, 0xFFFFFFF);
    mlx_loop(mlx_connection);
	(void)av;
    return (ac);
}
