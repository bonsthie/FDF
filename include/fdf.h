/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:38 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/07 23:40:40 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_F
#define FDF_F


#include <unistd.h>
#include <stdbool.h>

typedef struct s_vect2
{
    int x;
    int z;
}   t_vect2;

typedef struct s_vect3
{
	float vect3[4];
}   t_vect3;

typedef struct s_vertex
{
    float y;
	bool end;
}   t_vertex;

#endif
