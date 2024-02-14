/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/14 15:17:22 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "hook.h"
#include "libft.h"
#include "mlx.h"
#include "parsing/parsing.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double	calculate_zoom_size(int new_columns, int new_rows)
{
	double	original_area;
	double	new_area;
	double	area_ratio;

	original_area = 19 * 12;
	new_area = new_columns * new_rows;
	area_ratio = original_area / new_area;
	return (100.0 * sqrt(area_ratio));
}

double	find_biggest(double *y, int size_y)
{
	int		i;
	double	biggest;

	i = 0;
	biggest = 1;
	while (i < size_y)
	{
		if (y[i] > biggest)
			biggest = y[i];
		i++;
	}
	return (biggest);
}

int	init_map(t_map *map)
{
	t_position	*pos;
	t_animation	*anim;

	pos = malloc(sizeof(t_position));
	if (!pos)
		return (1);
	anim = malloc(sizeof(t_animation));
	if (!anim)
		return (1);
	map->color = malloc(map->height * map->width * sizeof(int));
	if (!map->color)
		return (1);
	standard_color(map);
	pos->yaw = 359.3;
	pos->pitch = 253.4;
	pos->zoom_start = calculate_zoom_size(map->width, map->height);
	pos->zoom = pos->zoom_start * 3;
	pos->offset_y = 550.0;
	pos->offset_x = 1000.0;
	map->y_scale = 20.0 / find_biggest(map->y, map->height * map->width);
	anim->start = true;
	anim->rotate = true;
	anim->mouse_rotation = false;
	anim->mouse_translation = false;
	anim->translation = NULL;
	map->anim = anim;
	map->pos = pos;
	return (0);
}

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
	printf("%x\n", (int)ft_strtol("0xa64c4c", NULL, 0) + 0xFF000000 - 0xFF000000);
	hook(map);
	mlx_loop_hook(mlx.connection, loop, map);
	mlx_loop(mlx.connection);
	destroy(map);
	return (ac);
}
