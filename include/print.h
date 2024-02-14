/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:46:27 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/13 22:20:25 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "fdf.h"

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
void	print_map(t_map *map, t_data *data);

#endif
