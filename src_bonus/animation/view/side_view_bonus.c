/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_view_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:41:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 10:52:47 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_position	*side_view(void)
{
	static t_position	pos = {.yaw = 90, .pitch = 180};

	return (&pos);
}
