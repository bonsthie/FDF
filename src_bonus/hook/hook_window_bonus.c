/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:30:45 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 11:12:34 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end(param);
	return (0);
}
