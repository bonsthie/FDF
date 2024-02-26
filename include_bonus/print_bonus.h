/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:27 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 16:18:51 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_BONUS_H
# define PRINT_BONUS_H

# include "fdf_bonus.h"

typedef struct s_line_parm
{
	int	first_point;
	int	second_point;
	int	d;
	int	s;
}		t_line_param;

void	plot_line(t_data *mlx, int *v1, int *v2, int color);
void	plot_line_high(t_data mlx, int *v1, int *v2, int color);
void	plot_line_low(t_data mlx, int *v1, int *v2, int color);
void	print_map_screen(t_data *mlx, t_map *map, int *coord);
void	print_map(t_map *map, t_data *data);

#endif