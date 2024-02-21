/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:38 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/17 18:14:05 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include <unistd.h>

# ifndef WIDTH
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 1080
# endif

# ifndef INCREMENT
#  define INCREMENT 5
# endif

typedef double	t_vec4d	__attribute__((vector_size(4 * sizeof(double))));

typedef struct s_data
{
	void				*connection;
	void				*window;
	void				*image;
	int					mouse_x;
	int					mouse_y;
}						t_data;

typedef struct s_position
{
	double				pitch;
	double				yaw;
	double				zoom;
	double				zoom_start;
	double				offset_x;
	double				offset_y;

}						t_position;

typedef struct s_animation
{
	bool				start;
	bool				rotate;
	bool				mouse_translation;
	bool				mouse_rotation;
	t_position			*translation;

}						t_animation;

typedef struct s_map
{
	t_data				*mlx;
	t_animation			*anim;
	t_position			*pos;
	double				*y;
	double				y_scale;
	unsigned int		*color;
	unsigned int		*standard_color;
	int					width;
	int					height;
}						t_map;

#endif
