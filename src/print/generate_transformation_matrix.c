/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_transformation_matrix.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:52:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/05 21:01:59 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	create_transformation_matrix(vec4d *transformation, t_map map)
{
	vec4d	*m_pitch;
	vec4d	*m_yaw;
	vec4d	*m_scale;
	vec4d	tempMatrix[4];
	double	cosPitch;
	double	sinPitch;
	double	cosYaw;
	double	sinYaw;

	map.pitch *= (M_PI / 180.0);
	map.yaw *= (M_PI / 180.0);
	cosPitch = cos(map.pitch);
	sinPitch = sin(map.pitch);
	cosYaw = cos(map.yaw);
	sinYaw = sin(map.yaw);
	m_pitch = (vec4d[4]){
	{1, 0, 0, -map.offset_x},
	{0, cosPitch, -sinPitch, -map.offset_y},
	{0, sinPitch, cosPitch, 0},
	{0, 0, 0, 1}};
	m_yaw = (vec4d[4]){
	{cosYaw, 0, sinYaw, -map.offset_x},
	{0, 1, 0, -map.offset_y},
	{-sinYaw, 0, cosYaw, 0},
	{0, 0, 0, 1}};
	m_scale = (vec4d[4]){
	{map.zoom, 0, 0, map.offset_x},
    {0, map.zoom, 0, map.offset_y},
    {0, 0, map.zoom, 0},
    {0, 0, 0, 1}};
	matrix_multiplication4x4(tempMatrix, m_pitch, m_yaw);
	matrix_multiplication4x4(transformation, tempMatrix, m_scale);
}
