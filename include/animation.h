/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:13:15 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/13 11:08:29 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "fdf.h"

void		transition(t_map *map, t_position end_position);
t_position	*isometric_vue(void);
t_position	*plan_vue(void);
void		apparition_animation(t_map *map);
void		rotate(t_map *map);

#endif
