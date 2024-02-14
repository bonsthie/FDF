/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_transformation_matrix.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:52:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/13 11:16:04 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "maths.h"

void	create_transformation_matrix(t_vec4d *transformation, t_map map)
{
	t_position_matrix	matrix;
	t_rotation_metrics	metrics;
	t_position			pos;
	t_vec4d				temp_matrix[4];

	pos = *map.pos;
	pos.pitch *= (M_PI / 180.0);
	pos.yaw *= (M_PI / 180.0);
	metrics.cos_pitch = cos(pos.pitch);
	metrics.sin_pitch = sin(pos.pitch);
	metrics.cos_yaw = cos(pos.yaw);
	metrics.sin_yaw = sin(pos.yaw);
	matrix.pitch = (t_vec4d[4]){
	{1, 0, 0, 0}, {0, metrics.cos_pitch, -metrics.sin_pitch, 0},
	{0, metrics.sin_pitch, metrics.cos_pitch, 0}, {0, 0, 0, 1}};
	matrix.yaw = (t_vec4d[4]){
	{metrics.cos_yaw, 0, metrics.sin_yaw, 0}, {0, 1, 0, 0},
	{-metrics.sin_yaw, 0, metrics.cos_yaw, 0}, {0, 0, 0, 1}};
	matrix.scale = (t_vec4d[4]){
	{map.pos->zoom, 0, 0, -((map.width - 1) * map.pos->zoom * 0.5)},
	{0, map.pos->zoom, 0, -map.pos->zoom},
	{0, 0, map.pos->zoom, -((map.height - 1) * map.pos->zoom * 0.5)},
	{0, 0, 0, 1}};
	matrix_multiplication4x4(temp_matrix, matrix.pitch, matrix.yaw);
	matrix_multiplication4x4(transformation, temp_matrix, matrix.scale);
}
