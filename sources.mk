# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 21:28:00 by babonnet          #+#    #+#              #
#    Updated: 2024/02/24 18:09:54 by babonnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addprefix $(SRC_DIR)/, \
	hook/loop_hook.c \
	hook/hook_mouse.c \
	hook/hook_window.c \
	hook/hook_keyboard.c \
	hook/hook.c \
	parsing/strs_to_point.c \
	parsing/fill_map.c \
	parsing/line_checker.c \
	parsing/parsing.c \
	print/print_line.c \
	print/generate_map.c \
	print/generate_transformation_matrix.c \
	print/print_map.c \
	color/montain_color.c \
	color/standard_color.c \
	init_map/utils_init_map.c \
	init_map/init_map.c \
	math/matrix4by1.c \
	math/matrix4by4.c \
	animation/transition.c \
	animation/apparition_animation.c \
	animation/view/isometric_view.c \
	animation/view/plan_view.c \
	animation/view/side_view.c \
	animation/rotate.c \
	fdf.c)

SRC_BONUS = $(addprefix $(SRC_DIR_BONUS)/, \
	hook/loop_hook_bonus.c \
	hook/hook_mouse_bonus.c \
	hook/hook_window_bonus.c \
	hook/hook_keyboard_bonus.c \
	hook/hook_bonus.c \
	parsing/strs_to_point_bonus.c \
	parsing/fill_map_bonus.c \
	parsing/line_checker_bonus.c \
	parsing/parsing_bonus.c \
	print/print_line_bonus.c \
	print/generate_map_bonus.c \
	print/generate_transformation_matrix_bonus.c \
	print/print_map_bonus.c \
	color/montain_color_bonus.c \
	color/standard_color_bonus.c \
	init_map/utils_init_map_bonus.c \
	init_map/init_map_bonus.c \
	math/matrix4by1_bonus.c \
	math/matrix4by4_bonus.c \
	animation/transition_bonus.c \
	animation/apparition_animation_bonus.c \
	animation/view/isometric_view_bonus.c \
	animation/view/plan_view_bonus.c \
	animation/view/side_view_bonus.c \
	animation/rotate_bonus.c \
	fdf_bonus.c)
