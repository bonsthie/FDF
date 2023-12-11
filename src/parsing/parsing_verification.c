/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:01:24 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/09 20:02:23 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

int line_size(char *line)
{
    int count;

    count = 0;
    while(*line)
    {
        if (*line == '\n')
            return (count);
        while (*line == ' ' && *line)
            line++;
        while(*line != ' ' && *line)
            line++;
        count++;
    }
    return (count);
}

int is_valid_map(int fd, t_map *map)
{
    int     line_len;
    char    *line;

    line = get_next_line(fd);
    map->width = 0;
    map->height = 0;
    while(line)
    {
        line_len = line_size(line);
        if (map->width == 0)
            map->width = line_len;
        else if (map->width != line_len)
            break;
        map->height++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
	map->height = map->height;
    if (map->width == line_len)
        return (map->height * map->width);
    return (0);
}
