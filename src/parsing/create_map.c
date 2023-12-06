/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:04:29 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/06 16:52:18 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"
#include "limit.h"
#include "libft.h"

int fill_line(int fd, t_vertex *map)
{
	char	*line;
	int		count;
	int		i;

	i = 0;
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (2147483647);
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		map[count].y = ft_atoi(&line[i]); // manage hexa
		map[count].end = false;
		count++;
		while(line[i] != ' ' && line[i])
			i++;
	}
	return (count);

}

t_vertex *create_map(int fd, int size)
{
    t_vertex *map;
    int     i;

    map = malloc((size + 1) * sizeof(t_vertex));
    if (!map)
        return (NULL);
    i = 0;
    while(i <= size)
    {
        i += fill_line(fd, &map[i]);
    }
	map[size].end = true;
	map[size].y = 0;
	return (map);
}
