/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:52:47 by bbonnet           #+#    #+#             */
/*   Updated: 2024/01/14 00:57:54 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include "parsing.h"

t_map *parsing_map(char *file)
{
    int     fd;
    t_map   *map;
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
    map = create_map(fd, size);
    close(fd);
    return (map);
}
