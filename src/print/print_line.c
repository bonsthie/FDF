/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:41:52 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/06 18:24:16 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"
#include "mlx.h"
#include "print.h"
#include <math.h>
#include <stdlib.h>

void print_line(void *mlx_connection, void *mlx_window, t_vect2 v1, t_vect2 v2)
{
    int dx;
    int dy;
    int sx;
    int sy;
    int e;
    int  e2;

    dx = abs(v2.x - v1.x);
    if (v1.x < v2.x)
        sx = 1;
    else
        sx = -1;
    dy = -abs(v2.z - v1.z);
    if (v1.z < v2.z)
        sy = 1;
    else
        sy = -1;
    e = dx + dy;
    while(1)
    {
        if (v1.x <= LENGTH && v1.z <= WIDTH)
            mlx_pixel_put(mlx_connection, mlx_window, v1.x, v1.z, 0xFFFFFFFF);
        if ((v1.x == v2.x) && (v1.z == v2.z))
            return ;
        e2 = 2 * e;
        if (e2 >= dy)
        {
            if (v1.x == v2.x)
                return ;
            e += dy;
            v1.x += sx;
        }
        if (e2 <= dx)
        {
            if (v1.z == v2.z)
                return ;
            e += dx;
            v1.z += sy;
        }
    }
}
