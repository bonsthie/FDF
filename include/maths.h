/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:59:45 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/13 11:14:56 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include "fdf.h"
# include <math.h>

typedef struct s_position_matrix
{
	t_vec4d	*pitch;
	t_vec4d	*yaw;
	t_vec4d	*scale;
}			t_position_matrix;

typedef struct s_rotation_metrics
{
	double	cos_pitch;
	double	sin_pitch;
	double	cos_yaw;
	double	sin_yaw;
}			t_rotation_metrics;

void		matrix_multiplication4x4(t_vec4d result[4], t_vec4d a[4],
				t_vec4d b[4]);
void		matrix_multiplication1x4(t_vec4d *matrix, t_vec4d vector,
				t_vec4d *result);
void		create_transformation_matrix(t_vec4d *transformation, t_map map);
#endif
