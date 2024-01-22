/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:04:29 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/18 14:26:22 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"
#include "limit.h"
#include "libft.h"


#include <stdio.h>

int fill_line(int fd, t_map *map, int start)
{
	char	*line;
	int		count;
	int		i;

	i = 0;
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (-2147483648);
	//char **parse_line = ft_split(line, ' ');
	//while(*parse_line)
	//{
	//	map->y[start + count] = ft_atoi[count];
	//	count++;
	//}
	//free(pare_line);
	//free(line);
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		map->y[start + count] = ft_atoi(&line[i]); // manage hexa
		count++;
		while(line[i] != ' ' && line[i])
			i++;
	}
	free(line);
	return (count);

}

t_map *create_map(int fd, int size)
{
    t_map	*map;
    int     i;
	int		tmp;

	map = malloc(sizeof(t_map));
    map->y = malloc(size * sizeof(double));
	map->height = 0;
    if (!map)
        return (NULL);
    i = 0;
    while(i < size)
    {
        tmp = fill_line(fd, map, i);
		if (tmp == -2147483648)
			break;
		i += tmp;
		map->height++;
    }
	map->width = tmp;
	printf("width ==%d  height == %d", map->width, map->height);
	return (map);
}
