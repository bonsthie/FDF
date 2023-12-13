/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:41:52 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/12 21:20:53 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define abs(value) ((value > 0) ? value : -value)
#define WIDTH 720
#define HEIGTH WIDTH * 9 / 16

void	plot_line_low(t_data mlx, int *v1, int *v2, int color)
{
	int	dx;
	int	dz;
	int	yi;
	int	D;
	int	z;
	int	x;

	yi = 1;
	dx = v2[0] - v1[0];
	dz = v2[1] - v1[1];
	if (dz < 0)
	{
		yi = -1;
		dz = -dz;
	}
	D = (2 * dz) - dx;
	z = v1[1];
	x = v1[0];
	printf("x1 = %d y1 = %d x2 = %d y2 = %d\nn", v1[0], v1[1], v2[0], v2[1]);
	while (x < v2[0])
	{
		if (x <= WIDTH && z <= HEIGTH)
			mlx_set_image_pixel(mlx.connection, mlx.image, x, z, color);
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


void plot_line_high(t_data mlx, int *v1, int *v2, int color)
{
    int dx = v2[0] - v1[0];
    int dy = v2[1] - v1[1]; 
	int xi = 1;
    int D = 2*dx - dy;
    int x = v1[0];

    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }

	printf("x1 = %d y1 = %d x2 = %d y2 = %d\n", v1[0], v1[1], v2[0], v2[1]);
    for (int y = v1[1]; y <= v2[1]; y++)
    {
		if (x <= WIDTH && y <= HEIGTH)
			mlx_set_image_pixel(mlx.connection, mlx.image, x, y, color);
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


void	plot_line(t_data data, int *v1, int *v2, int color)
{
	if (abs(v2[1]- v1[1]) < abs(v2[0] - v1[0]))
	{
		if (v1[0] > v2[0])
		{
			printf("1\n");
			plot_line_high(data, v2, v1, color);
		}
		else
		{
			printf("2\n");
			plot_line_low(data, v1, v2, color);
		}
	}
	else
	{
		if (v1[1] > v2[1])
		{
			printf("3\n");
			plot_line_high(data, v2, v1, color);
		}
		else
		{
			printf("4\n"); 
			plot_line_high(data, v1, v2, color);
		}
	}
}
