/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:13:15 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 16:18:28 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_BONUS_H
# define ANIMATION_BONUS_H

# include "fdf_bonus.h"

t_position	*isometric_view(void);
t_position	*plan_view(void);
t_position	*side_view(void);

void		transition(t_map *map, t_position end_position);
void		apparition_animation(t_map *map);
void		rotate(t_map *map);

void		standard_color(t_map *map);
void		montain_color(t_map *map);

#endif
