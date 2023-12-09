/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:48:42 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/09 19:32:13 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "print.h"
#include <math.h>
#include <stdlib.h>


#include <stdio.h>
#define WIDTH 720
#define HEIGHT WIDTH * 9 /16

float *orientation(void)
{
    static float matrix[16] = {0.0};
	float radian;
	float	zoom;
	float	angle = 0;

	zoom = 0.08;

    if (matrix[0] == 0)
    {   
        radian = 10 * 3.1416 / 180.0;

        matrix[0]  = zoom;
        matrix[10]  = zoom;
		matrix[7] = -sin(angle);
		matrix[5] =zoom;
		matrix[15] = 3.0;
    }
	(void)radian;
    return (matrix);
}

float *fov(void)
{
    static float matrix[16] = {0.0};
	float fov = 1.0 / tan(45.0 * 3.14159265358979323846 / 180.0 / 2.0);
	float aspect_ratio = (float)WIDTH / (float)HEIGHT;
	float near = 1.3;
	float far = 1000.0;


    if (matrix[0] == 0)
    {
		matrix[0] = fov * aspect_ratio;
		matrix[5] = fov;
		matrix[10] = (far+near)/(far-near);
		matrix[11] = 1.0;
		matrix[14] = (2.0 *near*far)/(near-far);
		matrix[15] = 0.2;

    }
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


void create_point2D(float *vect3, int *co)
{
	float *m_orientation = matrix_multiplication1x4(vect3, orientation());
	float *m_fov = matrix_multiplication1x4(m_orientation, fov());

	co[0] = ((m_fov[0]/ m_fov[3]) + 1) * (WIDTH / 2.0);
	co[1] = ((m_fov[1] / m_fov[3])) * ((float)HEIGHT / 2.0);
}

void print_map_screen(t_data data, t_map map, int *co)
{
	t_2d	p1;
	t_2d	p2;
	int		i;

	i = 0;
	while ()
	plotLine(mlx.connection, mlx.window, p1, p2, 0xE04062);
}


void print_map(t_map *map, t_data data)
{
	int *co;
	int		co_i;
	int i;
	int size;
	float vect3[4];

	size = map->width * map->height;
	i = 0;
	co = malloc(size * sizeof(int));
	co_i = 0;
	while (i < size)
	{
		vect3[0] = i % map->width;
		vect3[1] = map->y[i];
		vect3[2] = i / map->width;
		vect3[3] = 1.0f;
		create_point2D(vect3, &co[co_i]);
		i++;
		co_i += 2;
	}
	print_map_screen(data, co);
}
