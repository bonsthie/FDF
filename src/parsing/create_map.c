/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:04:29 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/06 02:43:38 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

t_vect3 *create_map(int fd, int size)
{
    t_vect3 *map;
    int     y;
    int     i;

    map = malloc((size + 1) * sizeof(t_vect3));
    if (!map)
        return (NULL);
    i = 0;
    y = 0;
    while(i <= size)
    {
        i += fill_line(fd, y, &map[i]);
        y++;
    }
    map->x = LENGTH
}
