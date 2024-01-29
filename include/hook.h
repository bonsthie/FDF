/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:59:09 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/29 11:32:31 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

void hook(t_map *map);
int loop(void *content);

int		window_hook(int event, void *param);
int		keyup_hook(int key, void *param);
int		mousewheel_hook(int key, void *param);
int		mousedown_hook(int key, void *param);
int		mouseup_hook(int key, void *param);

void	mouse_translation(t_map *map);
void	mouse_rotation(t_map *map);

#endif
