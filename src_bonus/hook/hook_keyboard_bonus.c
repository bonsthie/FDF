/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keyboard_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:00:22 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 11:12:34 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation_bonus.h"
#include "fdf_bonus.h"
#include "hook_bonus.h"
#include "mlx.h"
#include "print_bonus.h"

static void	offset_input(int key, t_position *pos)
{
	if (key == L_ARROW)
		pos->offset_x += 10.1;
	else if (key == R_ARROW)
		pos->offset_x -= 10.1;
	else if (key == DOWN_ARROW)
		pos->offset_y -= 10.1;
	else if (key == UP_ARROW)
		pos->offset_y += 10.1;
}

static void	rotation(int key, t_position *pos)
{
	if (key == W_KEY)
		pos->pitch += 3.1;
	else if (key == S_KEY)
		pos->pitch -= 3.1;
	else if (key == A_KEY)
		pos->yaw += 3.1;
	else if (key == D_KEY)
		pos->yaw -= 3.1;
}

static void	animation(int key, t_animation *anim)
{
	if (key == C_KEY)
		anim->rotate = !anim->rotate;
}

static void	view(int key, t_animation *anim)
{
	if (key == N1_KEY)
		anim->translation = isometric_view();
	else if (key == N2_KEY)
		anim->translation = plan_view();
	else if (key == N2_KEY + 1)
		anim->translation = side_view();
}

int	keyup_hook(int key, void *param)
{
	t_map	*map;

	map = param;
	if (key == ESCAPE)
		mlx_loop_end(map->mlx->connection);
	else if (key >= L_ARROW && key <= DOWN_ARROW)
		offset_input(key, map->pos);
	else if (key == A_KEY || key == W_KEY || key == S_KEY || key == D_KEY)
		rotation(key, map->pos);
	else if (key == C_KEY)
		animation(key, map->anim);
	else if (key == O_KEY)
		map->y_scale += 0.01;
	else if (key == L_KEY)
		map->y_scale -= 0.01;
	else if (key >= N1_KEY && key <= N5_KEY)
		view(key, map->anim);
	else if (key == N0_KEY)
		montain_color(map);
	else if (key == N9_KEY)
		standard_color(map);
	print_map(map, map->mlx);
	return (0);
}
