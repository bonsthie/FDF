/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:38 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/21 18:47:24 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_F
# define FDF_F

# include <stdbool.h>
# include <unistd.h>

#define WIDTH 720
#define HEIGHT 720 * 9 / 16

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
	double	vect3[4];
}			t_vect3;

typedef struct s_map
{
	double	*y;
	int		width;
	int		height;
	double	pitch;
	double	yaw;
	double	zoom;
	double	zoom_count;
	double	offset_x;
	double	offset_y;
}			t_map;

#endif
