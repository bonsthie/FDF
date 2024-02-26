/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:31:00 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 16:18:28 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MAP_BONUS_H
# define INIT_MAP_BONUS_H

# include "fdf_bonus.h"

double	calculate_zoom_size(int new_columns, int new_rows);
double	find_biggest(double *y, int size_y);

int		init_map(t_map *map);

#endif