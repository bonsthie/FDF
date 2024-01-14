/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:38 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/14 22:18:57 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_F
# define FDF_F

# include <stdbool.h>
# include <unistd.h>

typedef struct s_data
{
	void	*connection;
	void	*window;
	void	*image;
}			t_data;

typedef struct s_2d
{
	int		x;
	int		y;
}			t_2d;

typedef struct s_vect3
{
	float	vect3[4];
}			t_vect3;

typedef struct s_map
{
	float	*y;
	int		width;
	int		height;
	float	pitch;
	float	yaw;
	float	zoom;
	float	zoom_count;
	float	offset_x;
	float	offset_y;
}			t_map;

#endif
