/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_transformation_matrix.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:52:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/10 01:14:56 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

typedef struct s_position
{
	vec4d	*pitch;
	vec4d	*yaw;
	vec4d	*scale;
} t_position;

typedef struct s_rotation_metrics
{
	double	cosPitch;
	double	sinPitch;
	double	cosYaw;
	double	sinYaw;
} t_rotation_metrics;


void	create_transformation_matrix(vec4d *transformation, t_map map)
{
	t_position matrix;
	t_rotation_metrics metrics;
	vec4d	tempMatrix[4];

	map.pitch *= (M_PI / 180.0);
	map.yaw *= (M_PI / 180.0);
	metrics.cosPitch = cos(map.pitch);
	metrics.sinPitch = sin(map.pitch);
	metrics.cosYaw = cos(map.yaw);
	metrics.sinYaw = sin(map.yaw);
	matrix.pitch = (vec4d[4]){
	{1, 0, 0, 0},
	{0, metrics.cosPitch, -metrics.sinPitch, 0},
	{0, metrics.sinPitch, metrics.cosPitch, 0},
	{0, 0, 0, 1}};
	matrix.yaw = (vec4d[4]){
	{metrics.cosYaw, 0, metrics.sinYaw, 0},
	{0, 1, 0, 0},
	{-metrics.sinYaw, 0, metrics.cosYaw, 0},
	{0, 0, 0, 1}};
	matrix.scale = (vec4d[4]){
	{map.zoom, 0, 0, -((map.width - 1) * map.zoom * 0.5)},
    {0, map.zoom, 0, -map.zoom},
    {0, 0, map.zoom, -((map.height - 1) * map.zoom * 0.5)},
    {0, 0, 0, 1}};
	matrix_multiplication4x4(tempMatrix, matrix.pitch, matrix.yaw);
	matrix_multiplication4x4(transformation, tempMatrix, matrix.scale);
}
