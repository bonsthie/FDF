/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/17 18:34:54 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "hook.h"
#include "mlx.h"
#include "init_map.h"
#include "parsing.h"
#include <stdlib.h>

void	destroy(t_map *map)
{
	t_data	mlx;

	mlx = *map->mlx;
	free(map->y);
	free(map->color);
	if (map->anim)
		free(map->anim);
	if (map->pos)
		free(map->pos);
	if (map->standard_color)
		free(map->standard_color);
	free(map);
	mlx_destroy_image(mlx.connection, mlx.image);
	mlx_destroy_window(mlx.connection, mlx.window);
	mlx_destroy_display(mlx.connection);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_data	mlx;

	map = parsing_map(av[1]);
	if (!map)
		return (1);
	mlx.connection = mlx_init();
	mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "FDF");
	mlx.image = NULL;
	map->mlx = &mlx;
	mlx.mouse_x = -1;
	mlx.mouse_y = -1;
	if (init_map(map))
	{
		destroy(map);
		return (1);
	}
	hook(map);
	mlx_loop_hook(mlx.connection, loop, map);
	mlx_loop(mlx.connection);
	destroy(map);
	return (ac);
}
