/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:27 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/09 16:42:59 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H

#include "fdf.h"

void	plotLine(void *mlx_connection, void *mlx_window, t_2d v1, t_2d v2, int color);
void	plot_line_high(void *mlx_connection, void *mlx_window, t_2d v1, t_2d v2, int color);
void	plot_line_low(void *mlx_connection, void *mlx_window, t_2d v1, t_2d v2, int color);
void	print_map(t_map *map, void *mlx_co, void *mlx_window);

#endif
