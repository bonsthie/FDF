NAME = FDF

CC = clang
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
HSRCS = include
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
NC = \033[0m 


LIBRARIES = LIBFT LIBMLX

LIBFT_FLAG = -lft
LIBFT_DIR = libft
LIBFT_INCLUDE = .

LIBMLX_DIR = MacroLibX
LIBMLX_FLAG = -lmlx -lSDL2 -Wl,-rpath,$(LIBMLX_DIR)
LIBMLX_INCLUDE = includes

LIB = $(foreach lib,$(LIBRARIES),-L $($(lib)_DIR) $($(lib)_FLAG))
LIB_DIR = $(foreach lib,$(LIBRARIES),-I $($(lib)_DIR)/$($(lib)_INCLUDE))

all: libraries $(NAME)


$(NAME): $(OBJS)
	@echo -e "$(GREEN)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) $(DEBUG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@echo -e "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -I $(HSRCS) $(LIB_DIR) -o $@ -c $< $(DEBUG)

libraries:
	@echo -e "$(YELLOW)Building libraries...$(NC)"
	$(foreach lib,$(LIBRARIES), $(MAKE) -C $($(lib)_DIR);)

clean:
	@echo -e "$(RED)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)

lclean:
	@echo -e "$(RED)Cleaning libraries...$(NC)"
	@$(foreach lib,$(LIBRARIES),$(MAKE) -C $($(lib)_DIR) clean;)

fclean: clean lclean
	@echo -e "$(RED)Cleaning executable $(NAME)...$(NC)"
	@rm -f $(NAME)
	@$(foreach lib,$(LIBRARIES),$(MAKE) -C $($(lib)_DIR) fclean;)

.PHONY: all clean fclean lclean re libraries
