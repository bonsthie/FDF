/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:30:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/17 18:32:02 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	calculate_zoom_size(int new_columns, int new_rows)
{
	double	original_area;
	double	new_area;
	double	area_ratio;

	original_area = 19 * 12;
	new_area = new_columns * new_rows;
	area_ratio = original_area / new_area;
	return (100.0 * sqrt(area_ratio));
}

double	find_biggest(double *y, int size_y)
{
	int		i;
	double	biggest;

	i = 0;
	biggest = 1;
	while (i < size_y)
	{
		if (y[i] > biggest)
			biggest = y[i];
		i++;
	}
	return (biggest);
}
