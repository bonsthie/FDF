/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:38 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/09 19:32:19 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_F
#define FDF_F


#include <unistd.h>
#include <stdbool.h>

typedef struct s_data
{
	void *connection;
	void *window;
} t_data;

typedef struct s_2d
{
    int x;
    int y;
}   t_2d;

typedef struct s_vect3
{
	float vect3[4];
}   t_vect3;

typedef struct s_map
{
    float *y;
	int width;
	int height;
}   t_map;

#endif
