/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:59:09 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/17 19:52:22 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "fdf.h"

enum	e_keycode
{
	A_KEY = 4,
	C_KEY = 6,
	D_KEY = 7,
	L_KEY = 15,
	O_KEY = 18,
	S_KEY = 22,
	W_KEY = 26,
	N1_KEY = 30,
	N2_KEY = 31,
	N3_KEY = 32,
	N4_KEY = 33,
	N5_KEY = 34,
	N9_KEY = 38,
	N0_KEY = 39,
	ESCAPE = 41,
	L_ARROW = 79,
	R_ARROW = 80,
	UP_ARROW = 81,
	DOWN_ARROW = 82,
};

void	hook(t_map *map);
int		loop(void *content);

int		window_hook(int event, void *param);
int		keyup_hook(int key, void *param);
int		mousewheel_hook(int key, void *param);
int		mousedown_hook(int key, void *param);
int		mouseup_hook(int key, void *param);

void	mouse_translation(t_map *map);
void	mouse_rotation(t_map *map);

#endif
