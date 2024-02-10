/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4by1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:38:38 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/10 15:12:59 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

__attribute__((always_inline)) void	matrix_multiplication1x4(vec4d *matrix,
	vec4d vector, vec4d *result)
{
	int		i;
	vec4d	product;
	double	dot_product;

	*result = (vec4d){0, 0, 0, 0};
	i = 0;
	while (i < 4)
	{
		product = matrix[i] * vector;
		dot_product = product[0] + product[1] + product[2] + product[3];
		(*result)[i] = dot_product;
		i++;
	}
}
