# ********************************************************************************* #
#                                                                                   #
#                                                            :::      ::::::::      #
#      Makefile                                            :+:      :+:    :+:      #
#                                                        +:+ +:+         +:+        #
#      By: babonnet <babonnet@42angouleme.fr>          +#+  +:+       +#+           #
#                                                    +#+#+#+#+#+   +#+              #
#      Created: 2024/02/20 23:45:30 by babonnet           #+#    #+#                #
#      Updated: 2024/02/20 23:45:30 by babonnet          ###   ########.fr          #
#                                                                                   #
# ********************************************************************************* #

NAME = fdf

##################################### DATA ##########################################
CC = clang
CFLAGS = -Wall -Wextra -Werror -mavx -MMD -MP
SRC_DIR = src
OBJ_DIR = obj
HSRCS = include
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

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

################################### LIBRARIES #######################################
LIBRARIES = LIBFT LIBMLX

LIBFT_DIR = libft
LIBFT_BINARY = $(LIBFT_DIR)/libft.a
LIBFT_FLAG = -lft
LIBFT_INCLUDE = .

LIBMLX_DIR = MacroLibX
LIBMLX_BINARY = $(LIBMLX_DIR)/libmlx.so
LIBMLX_FLAG = -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR)
LIBMLX_INCLUDE = includes

LIB = $(foreach lib,$(LIBRARIES),-L$($(lib)_DIR) $($(lib)_FLAG))
LIB_DIR = $(foreach lib,$(LIBRARIES),-I $($(lib)_DIR)/$($(lib)_INCLUDE))
LIBS_BINARYS += $(foreach lib,$(LIBRARIES), $($(lib)_BINARY))

# Additional linker flags
ADDITIONAL_FLAGS = -lm

################################ MAKEFILE RULES #####################################
all: $(NAME)

$(NAME): $(LIBS_BINARYS) $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIB) $(ADDITIONAL_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -I$(HSRCS) $(LIB_DIR) -c $< -o $@

$(LIBS_BINARYS):
	@echo "$(PURPLE)Building library $(notdir $@)...$(NC)"
	@$(MAKE) -C $(@D) -j --no-print-directory all

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)

bonus : re
	@echo "$(GREEN)Linking bonus...$(NC)"

lclean:
	@echo "$(RED)Cleaning libraries obj...$(NC)"
	@$(foreach lib,$(LIBRARIES),$(MAKE) -C $($(lib)_DIR) clean > /dev/null;)

fclean: clean
	@echo "$(RED)Cleaning executable $(NAME)...$(NC)"
	@rm -f $(NAME)
	@echo "$(RED)Cleaning libraries...$(NC)"
	@$(foreach lib,$(LIBRARIES),$(MAKE) -C $($(lib)_DIR) fclean > /dev/null;)

re: fclean all

-include $(OBJ:.o=.d)

.PHONY: all clean fclean lclean re

##################################### COLORS ########################################
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m
