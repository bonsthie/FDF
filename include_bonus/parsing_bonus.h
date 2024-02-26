/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:01:55 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/26 16:18:28 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "fdf_bonus.h"
# include "libft.h"

int		is_valid_map(int fd);
t_map	*parsing_map(char *file);
t_map	*create_map(int fd, int size);
int		check_line_size(int line_size, char **strs);
t_map	*fill_map(t_list *head);
void	strs_to_point(char **strs, double *y, unsigned int *color);

#endif
