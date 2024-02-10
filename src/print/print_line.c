/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:41:52 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/09 23:41:48 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <stdlib.h>

void	plot_line(t_data *mlx, int *v1, int *v2, int color)
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sy;
	int	sx;
	int	err;
	int	e2;

	x1 = v1[0];
	y1 = v1[1];
	x2 = v2[0];
	y2 = v2[1];
	sx = -1;
	sy = -1;
	dx = abs(x2 - x1);
	if (x1 < x2)
		sx = 1;
	dy = -abs(y2 - y1);
	if (y1 < y2)
		sy = 1;
	err = dx + dy;
	while (1)
	{
		if (x1 < WIDTH && y1 < HEIGHT && x1 >= 0 && y1 >= 0)
			mlx_set_image_pixel(mlx->connection, mlx->image, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x1 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}
