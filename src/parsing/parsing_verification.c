/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_verification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:01:24 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/06 02:01:39 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int is_valid_map(int fd)
{
    int     size;
    int     line_len;
    char    *line;
    int     count;

    line = get_next_line(fd);
    size = 0;
    count = 0;
    while(line)
    {
        line_len = line_size(line);
        if (size == 0)
            size = line_len;
        else if (size != line_len)
            break;
        count++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    if (size == line_len)
        return (count * size);
    return (0);
}
