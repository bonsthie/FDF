/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:52:47 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/14 15:48:50 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parsing.h"
#include <fcntl.h>
#include <stdio.h>

void	pop_strs(void *value)
{
	free_strs(value);
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

t_list	*get_map_from_file(int fd)
{
	t_list	*head;
	char	*line;
	char	**split_line;
	int		line_size;

	head = NULL;
	line_size = -1;
	line = get_next_line(fd);
	while (line)
	{
		split_line = ft_split(line, ' ');
		free(line);
		line_size = check_line_size(line_size, split_line);
		if (line_size != -1)
			ft_lstadd_back(&head, ft_lstnew(split_line));
		else
		{
			free_strs(split_line);
			ft_lstclear(&head, pop_strs);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	free(line);
	return (head);
}

void	strs_to_point(char **strs, double *y, unsigned int *color)
{
	if (!strs)
		return ;
	while (*strs)
	{
		*y = ft_atoi(*strs);
		strs++;
		if (!*strs)
		{
			*color = 0xFFFFFFFF;
			break ;
		}
		if (!ft_strncmp(*strs, "0x", 2))
		{
			*color = ft_strtol(*strs, NULL, 0) + 0xFF000000;
			strs++;
		}
		else
			*color = 0xFFFFFFFF;
		y++;
		color++;
	}
}

int	fill_map_point(t_map *map, t_list *head)
{
	int	position;

	map->y = malloc(map->height * map->width * sizeof(double));
	if (!map->y)
		return (1);
	map->standard_color = malloc(map->height * map->width * sizeof(int));
	position = 0;
	if (!map->standard_color)
	{
		free(map->y);
		return (1);
	}
	while (head)
	{
		strs_to_point(head->content, &map->y[position],
			&map->standard_color[position]);
		position += map->width;
		head = head->next;
	}
	return (0);
}

t_map	*fill_map(t_list *head)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = ft_lstsize(head);
	map->width = check_line_size(-1, head->content);
	if (fill_map_point(map, head))
	{
		free(map);
		return (NULL);
	}
	return (map);
}

t_map	*parsing_map(char *file)
{
	t_map	*map;
	t_list	*head;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	head = get_map_from_file(fd);
	if (!head)
		return (NULL);
	map = fill_map(head);
	ft_lstclear(&head, pop_strs);
	return (map);
}
