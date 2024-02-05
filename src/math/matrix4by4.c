/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4by4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 20:31:44 by babonnet          #+#    #+#             */
/*   Updated: 2024/02/05 20:57:04 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void matrix_multiplication4x4(vec4d result[4], vec4d a[4], vec4d b[4]) {
	int i;
	int j;
	vec4d temp;
	vec4d replicated;

	i = 0;
    while (i < 4) {
        temp = (vec4d){0, 0, 0, 0};
		j = 0;
        while (j < 4) {
            replicated = (vec4d){a[i][j], a[i][j], a[i][j], a[i][j]};
            temp += replicated * b[j];
			j++;
        }
        result[i] = temp;
		i++;
    }
}
