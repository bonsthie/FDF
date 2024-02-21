/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:58:17 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/17 17:58:37 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_line_size(int line_size, char **strs)
{
	int	new_size;

	if (!strs)
		return (-1);
	new_size = 0;
	while (strs[new_size])
	{
		if (*strs[new_size] == '\n')
			break ;
		if (!ft_strncmp(strs[new_size], "0x", 2) && !ft_isint(strs[new_size]))
			return (-1);
		new_size++;
		if (!strs[new_size])
			break ;
		if (!ft_strncmp(strs[new_size], "0x", 2))
			strs++;
	}
	if (line_size == -1 || line_size == new_size)
		return (new_size);
	return (-1);
}
