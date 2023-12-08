/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:41:52 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/08 08:10:38 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define abs(value) ((value > 0) ? value : -value)

void	plot_line_low(void *mlx_connection, void *mlx_window, t_vect2 v1, t_vect2 v2, int color)
{
	int	dx;
	int	dz;
	int	yi;
	int	D;
	int	z;
	int	x;

	yi = 1;
	dx = v2.x - v1.x;
	dz = v2.z - v1.z;
	if (dz < 0)
	{
		yi = -1;
		dz = -dz;
	}
	D = (2 * dz) - dx;
	z = v1.z;
	x = v1.x;
	while (x < v2.x)
	{
		mlx_pixel_put(mlx_connection, mlx_window, x, z, color);
		if (D > 0)
		{
			z += yi;
			D += 2 * (dz - dx);
		}
		else
			D += 2 * dz;
		x++;
	}
}


void plot_line_high(void *mlx_connection, void *mlx_window, t_vect2 v1, t_vect2 v2, int color)
{
    int dx = v2.x - v1.x;
    int dy = v2.z - v1.z; // Renamed dz to dy for clarity
    int xi = 1;
    int D = 2*dx - dy;
    int x = v1.x;

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }

    for (int y = v1.z; y <= v2.z; y++)
    {
        mlx_pixel_put(mlx_connection, mlx_window, x, y, color);
        if (D > 0)
        {
            x += xi;
            D += 2 * (dx - dy);
        }
        else
        {
            D += 2 * dx;
        }
    }
}


void	plotLine(void *mlx_connection, void *mlx_window, t_vect2 v1, t_vect2 v2, int color)
{
	if (abs(v2.z - v1.z) < abs(v2.x - v1.x))
	{
		if (v1.x > v2.x)
		{
			printf("1\n");
			plot_line_high(mlx_connection, mlx_window, v2, v1, color);
		}
		else
		{
			printf("2\n"); //good
			plot_line_low(mlx_connection, mlx_window, v1, v2, color);
		}
	}
	else
	{
		if (v1.z > v2.z)
		{
			printf("3\n"); //bad
			plot_line_high(mlx_connection, mlx_window, v2, v1, color);
		}
		else
		{
			printf("4\n"); //bad0xFFFFFFFF
			plot_line_high(mlx_connection, mlx_window, v1, v2, color);
		}
	}
}
