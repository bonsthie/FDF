/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:27 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/09 20:13:09 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H

#include "fdf.h"

void	plot_line(t_data data, int *v1, int *v2, int color);
void plot_line_high(t_data mlx, int *v1, int *v2, int color);
void	plot_line_low(t_data mlx, int *v1, int *v2, int color);
void	print_map(t_map *map, t_data mlx);

#endif
