/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/08 08:44:07 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"
#include <math.h>
#include <stdlib.h>


#include <stdio.h>

float *orientation(void)
{
    static float matrix[16] = {0.0};
	float radian;
	float	zoom;

	zoom = 150.0;

    if (matrix[0] == 0)
    {   
        radian = 20 * 3.1416 / 180.0;

        matrix[0]  = zoom;
        matrix[5]  = zoom;
        matrix[10] = zoom;
        matrix[15] = 1.0;
		matrix[3] = 1.0;
		matrix[7] = 1.0;
		matrix[11] = 1.0;
    }
	(void)radian;
    return (matrix);
}

float *matrix_multiplication1x4(float *v, float *transformation) //opti
{
	float *matrix;
	int i;

	i = 0;
	matrix = malloc(4 * sizeof(float));
	if (!matrix)
		return (NULL);
	while (i < 4)
		matrix[i++] = 0;
	i = 0;
	while (i < 16)
	{
		matrix[i / 4] += transformation[i] * v[i % 4];
		i++;		
	}
	return (matrix);
}


void print_vect(void *mlx_co, void *mlx_window, float *v1, float *v2, float *v3)
{
	float *v1_m = matrix_multiplication1x4(v1, orientation());
	float *v2_m = matrix_multiplication1x4(v2, orientation());
	float *v3_m = matrix_multiplication1x4(v3, orientation());

	t_vect2 p1;
	t_vect2 p2;
	t_vect2 p3;

	p1.x = v1_m[0] / v1_m[2];
	p1.z = v1_m[1] / v1_m[2];

	p2.x = v2_m[0] / v2_m[2];
	p2.z = v2_m[1] / v2_m[2];

	p3.x = v3_m[0] / v3_m[2];
	p3.z = v3_m[1] / v3_m[2];

	printf("p1.x == %d p1.z == %d\np2.x == %d p2.z == %d\np3.x == %d p3.z == %d\n\n", p1.x, p1.z, p2.x, p2.z, p3.x, p3.z);
	plotLine(mlx_co, mlx_window, p1, p2, 0xE04062);
	plotLine(mlx_co, mlx_window, p1, p3, 0xFFFFFF);

}

void print_map(t_vertex *map, void *mlx_co, void *mlx_window)
{
	int i = 0;
	int size = 8;
	float v1[4];
	float v2[4];
	float v3[4];

	i = 0;
	while (map[i].end == false)
	{
		v1[0] = i % size;
		v1[1] = map[i].y;
		v1[2] = (float)(i / size);
		v1[3] = 1.0;
		v2[0] = i + 1 % size;
		v2[1] = map[i + 1].y;
		v2[2] = (float)(i + 1 / size);
		v2[3] = 1.0;
		v3[0] = v1[0];
		v3[1] = map[i + 1].y;
		v3[2] = v1[2] + 1;
		v3[3] = 1.0;
		if ((i + 1) % 8 != 0)
			print_vect(mlx_co, mlx_window, v1, v2, v3);
		i++;
	}
}
