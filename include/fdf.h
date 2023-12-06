/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:04:38 by bbonnet           #+#    #+#             */
/*   Updated: 2023/12/06 02:45:51 by bbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_F
#define FDF_F

#define LENGTH 720
#define WIDTH LENGTH * 9 / 16



typedef struct s_vect2
{
    int x;
    int y;
}   t_vect2;

typedef struct s_vect3
{
    int x;
    int y;
    int z;
}   t_vect3;

#endif
