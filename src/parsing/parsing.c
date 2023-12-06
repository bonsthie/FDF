/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:52:47 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/06 02:04:18 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "parsing.h"

t_vect3 *create_map(char *file)
{
    int     fd;
    t_vect3 *map;
    int     size;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    size = is_valid_map(fd);
    close(fd);
    if (!size)
        return (NULL);
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (NULL);
    map = parsing_map(fd);
    close(fd);
    return (map);
}
