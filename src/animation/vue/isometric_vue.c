/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_vue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:37:14 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/13 11:33:42 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_position	*isometric_vue(void)
{
	static t_position	vue = {.pitch = 210, .yaw = 322};

	return (&vue);
}
