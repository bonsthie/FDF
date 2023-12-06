/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/06 18:09:01 by babonnet         ###   ########.fr       */
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
    mlx_loop(mlx_connection);

    return (ac);
}
