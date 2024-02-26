/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:58:17 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/26 11:12:59 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_valid_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '\n')
			return (1);
		str++;
	}
	return (0);
}

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
		if (is_valid_number(strs[new_size]))
			return (-1);
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
