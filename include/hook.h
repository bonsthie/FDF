/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:59:09 by babonnet          #+#    #+#             */
/*   Updated: 2024/01/31 21:12:04 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
#define HOOK_H

int	window_hook(int event, void *param);
int	keyup_hook(int key, void *param);
int	mousewheel(int key, void *param);
int	mousedown_hook(int key, void *param);

#endif
