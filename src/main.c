/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/15 00:07:43 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "print.h"
#include "parsing/parsing.h"

#define LENGTH 720
#define WIDTH LENGTH * 9 / 16


#include <stdio.h>


t_data		mlx;

void refresh_screen(t_data data)
{
	int i;
	int j;

	i = 0;
	while (i < LENGTH)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_set_image_pixel(data.connection, data.image, i, j, 0x00000000);
			j++;
		}
		i++;
	}
}

int window_hook(int event, void* param)
{
    if(event == 0)
        mlx_loop_end(param);
    return (0);
}

int keyup_hook(int key, void* param)
{
	t_map *map;

	map = param;
	if (key == 79)
		map->offset_x += 0.1f;
	else if (key == 80)
		map->offset_x -= 0.1f;
	else if (key == 82)
		map->offset_y -= 0.1f;
	else if (key == 81)
		map->offset_y += 0.1f;
	else 
		return (1);
	//printf("hook %d", key);
	refresh_screen(mlx);
	print_map(map, mlx);

	return (0);
}

int mousedown_hook(int key, void *param)
{
	t_map *map;

	map = param;
	if (key == 1)
		map->zoom += 0.1;
	else if (key == 3)
		map->zoom -= 0.1;
	else 
		return (1);
	//printf("hook %d", key);
	refresh_screen(mlx);
	print_map(map, mlx);
	return (0);	
}

int mousewheel(int key, void *param)
{
	t_map *map;
	int x;
	int y;

	map = param;
	if (key == 1)
		map->zoom_count *= 1.01; 

	// Zoom out
	else if (key == 2)
	{
		map->zoom_count /= 1.01; 
		if (map->zoom_count < 0.1)
			map->zoom_count = 0.1;
	}
	else 
		return (1);
	map->zoom = map->zoom_count;
	mlx_mouse_get_pos(mlx.connection, &x, &y);
	map->offset_x = x - (x - map->offset_x) * map->zoom;
    map->offset_y = y - (y - map->offset_y) * map->zoom;
	printf("zooom ======= %.2f\n", map->zoom);
	refresh_screen(mlx);
	print_map(map, mlx);
	return (0);	
}


int main(int ac, char **av)
{
	t_map	*map;

	map = parsing_map(av[1]);
	for (int i = 0; i < map->width * map->height; i++)
		printf("%d = %.1f \n", i, map->y[i]);
	mlx.image = NULL;
    mlx.connection = mlx_init();
    mlx.window = mlx_new_window(mlx.connection, LENGTH, WIDTH, "FDF");
	map->yaw = 0.8f;
	map->pitch = 0.7f;	
	map->zoom_count = 0.2f;
	map->zoom = map->zoom_count;
	map->offset_x = 0.0;
	map->offset_y = 0.0;
	mlx.image = mlx_new_image(mlx.connection, LENGTH, WIDTH);
	print_map(map, mlx);


	mlx_on_event(mlx.connection, mlx.window, MLX_WINDOW_EVENT, window_hook, mlx.connection);
	mlx_on_event(mlx.connection, mlx.window, MLX_KEYDOWN, keyup_hook, map);
	mlx_on_event(mlx.connection, mlx.window, MLX_MOUSEDOWN, mousedown_hook, map);
	mlx_on_event(mlx.connection, mlx.window, MLX_MOUSEWHEEL, mousewheel, map);


    mlx_loop(mlx.connection);
	(void)av;
    return (ac);
    mlx_destroy_window(mlx.connection, mlx.window);
    mlx_destroy_display(mlx.connection);
}
