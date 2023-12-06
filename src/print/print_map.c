/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/06 20:53:41 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"
#include <math.h>


#include <math.h>

float *orientation(void)
{
    static float matrix[16] = {0.0};
	float radian;

    if (matrix[0] == 0)
    {   
        radian = 20 * 3.1416 / 180.0;

        matrix[0]  = 50.0;
        matrix[5]  = cos(radian) * 50.0;
        matrix[6]  = -sin(radian);
        matrix[9]  = sin(radian);
        matrix[10] = cos(radian) * 50.0;
        matrix[15] = 1.0;
    }
    return matrix;
}

float *matrix_multiplication(float *v, float *transforamtion) //opti
{
	int tab[3];
	int i;

	i = 0;
	while (i < 16)
	{
		tab[i % 4] = 
		
	}
}


void print_vect(void *mlx_co, void *mlx_window, t_vect3 v1, t_vect3 v2)
{
}

void print_map(t_vertex *map, void *mlx_co, void *mlx_window)
{
	int	i;
	int size = 8;
	t_vect3 v1;
	t_vect3 v2;

	i = 0;
	while (map[i].end == false)
	{
		v1.vect3[0] = i % size;
		v1.vect3[1] = map[i].y;
		v1.vect3[2] = (float)(i / size);
		v2.vect3[0] = v1.vect3[0] + 1;
		v2.vect3[1] = map[i + 1].y;
		v2.vect3[2] = v1.vect3[2];
		print_vect(mlx_co, mlx_window, v1, v2);
		v2.vect3[0] = v1.vect3[0];
		v2.vect3[1] = map[i + size].y;
		v2.vect3[2] = v1.vect3[2] + 1;
		print_vect(mlx_co, mlx_window, v1, v2);
		i++;
	}
}
