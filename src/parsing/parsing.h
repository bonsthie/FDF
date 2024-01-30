/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:01:55 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/29 20:19:40 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "fdf.h"

int		is_valid_map(int fd);
t_map	*parsing_map(char *file);
t_map	*create_map(int fd, int size);

#endif
