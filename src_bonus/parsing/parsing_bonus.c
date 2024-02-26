/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:52:47 by bbonnet           #+#    #+#             */
/*   Updated: 2024/02/26 15:15:45 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "libft.h"
#include "parsing_bonus.h"
#include <fcntl.h>
#include <stdio.h>

void	pop_strs(void *value)
{
	free_strs(value);
}

void	free_map_file_error(char **split_line, t_list *head)
{
	free_strs(split_line);
	get_next_line(-1);
	ft_lstclear(&head, pop_strs);
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
			free_map_file_error(split_line, head);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	free(line);
	return (head);
}

t_map	*parsing_map(char *file)
{
	t_map	*map;
	t_list	*head;
	int		fd;

	if (!file)
		return (NULL);
	if (ft_strcmp(&file[ft_strlen(file) - 4], ".fdf"))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	head = get_map_from_file(fd);
	close(fd);
	if (!head)
		return (NULL);
	map = fill_map(head);
	ft_lstclear(&head, pop_strs);
	return (map);
}
