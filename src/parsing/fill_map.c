/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:16:34 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/17 18:17:39 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parsing.h"

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
