/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs_to_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:18:14 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/17 18:18:26 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	strs_to_point(char **strs, double *y, unsigned int *color)
{
	if (!strs)
		return ;
	while (*strs)
	{
		*y = ft_atoi(*strs);
		strs++;
		if (!*strs)
		{
			*color = 0xFFFFFFFF;
			break ;
		}
		if (!ft_strncmp(*strs, "0x", 2))
		{
			*color = ft_strtol(*strs, NULL, 0) + 0xFF000000;
			strs++;
		}
		else
			*color = 0xFFFFFFFF;
		y++;
		color++;
	}
}
