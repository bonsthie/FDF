/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:27:11 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 11:12:34 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "hook_bonus.h"
#include "mlx.h"

void	hook(t_map *map)
{
	t_data	mlx;

	mlx = *map->mlx;
	mlx_on_event(mlx.connection, mlx.window, MLX_WINDOW_EVENT, window_hook,
		mlx.connection);
	mlx_on_event(mlx.connection, mlx.window, MLX_KEYDOWN, keyup_hook, map);
	mlx_on_event(mlx.connection, mlx.window, MLX_MOUSEDOWN, mousedown_hook,
		map);
	mlx_on_event(mlx.connection, mlx.window, MLX_MOUSEUP, mouseup_hook, map);
	mlx_on_event(mlx.connection, mlx.window, MLX_MOUSEWHEEL, mousewheel_hook,
		map);
}
