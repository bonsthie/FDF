/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:27 by babonnet          #+#    #+#             */
/*   Updated: 2023/12/06 17:55:11 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
#define PRINT_H

#include "fdf.h"

void print_line(void *mlx_connection, void *mlx_window, t_vect2 v1, t_vect2 v2);
void print_map(t_vertex *map, void *mlx_co, void *mlx_window);

#endif
