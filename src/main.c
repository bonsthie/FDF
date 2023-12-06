/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:25 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/06 00:51:13 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "mlx.h"
#include "fdf.h"

#define LENGTH 720
#define WIDTH LENGTH * 9 / 16

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
    dy = -abs(v2.y - v1.y);
    if (v1.y < v2.y)
        sy = 1;
    else
        sy = -1;
    e = dx + dy;
    while(1)
    {
        if (v1.x <= LENGTH && v1.y <= WIDTH)
            mlx_pixel_put(mlx_connection, mlx_window, v1.x, v1.y, 0xFFFFFFFF);
        if ((v1.x == v2.x) && (v1.y == v2.y))
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
            if (v1.y == v2.y)
                return ;
            e += dx;
            v1.y += sy;
        }
    }
}

int main(int ac, char **av)
{
    void    *mlx_connection;
    void    *mlx_window;
    t_vect2 first;
    t_vect2  second;

    first.x = ft_atoi(av[1]);
    first.y = ft_atoi(av[2]);
    second.x = ft_atoi(av[3]);
    second.y = ft_atoi(av[4]);

    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, LENGTH, WIDTH, "test");
    print_line(mlx_connection, mlx_window, first, second);
    mlx_loop(mlx_connection);

    return (ac);
}
