/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:38 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/07 13:39:11 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_F
# define FDF_F

# include <stdbool.h>
# include <unistd.h>

#ifndef WIDTH
# define WIDTH 1080
#endif

#ifndef HEIGHT
# define HEIGHT 1080 * 9 / 16
#endif

typedef double vec4d __attribute__((vector_size(4 * sizeof(double))));

typedef struct s_data
{
	void	*connection;
	void	*window;
	void	*image;
}			t_data;

typedef struct s_map
{
	t_data  *mlx;
	double	*y;
	int		*color;
	int		width;
	int		height;
	double	pitch;
	double	yaw;
	double	zoom;
	double  zoom_start;
	double	offset_x;
	double	offset_y;
	int		mouse_x;
	int		mouse_y;
	bool	start;
	bool	rotate;
	bool	mouse_translation;
	bool	mouse_rotation;
}			t_map;

void	refresh_screen(t_data *data);
void matrix_multiplication4x4(vec4d result[4], vec4d a[4], vec4d b[4]);
void matrix_multiplication1x4(vec4d *matrix, vec4d vector, vec4d *result);
void	create_transformation_matrix(vec4d *transformation, t_map map);

#endif
