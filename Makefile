NAME    = fdf

CC      = cc
CFLAGS = -Wall -Wextra -Werror -g3 -O3 -march=native -flto -funroll-loops -ftree-vectorize -fomit-frame-pointer

SRC_DIR     = fdf_dir
GNL_DIR     = gnl
LIBFT_DIR   = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR     = includes
MLX_DIR     = minilibx-linux
OBJ_DIR     = objs
MLX         = $(MLX_DIR)/libmlx_Linux.a -L/usr/lib -lXext -lX11 -lm

SRCS    = $(SRC_DIR)/main.c \
          $(SRC_DIR)/draw/draw_map.c $(SRC_DIR)/draw/projection.c \
          $(SRC_DIR)/draw/rotate.c $(SRC_DIR)/draw/draw_colors_line.c \
		  $(SRC_DIR)/draw/draw_colors_point.c \
		  $(SRC_DIR)/draw/manage_colors.c \
		  $(SRC_DIR)/draw/display.c \
          $(SRC_DIR)/fdf.c \
          $(SRC_DIR)/events/events_mouse.c $(SRC_DIR)/events/events_utils.c \
          $(SRC_DIR)/parse/parse_allocate_map.c $(SRC_DIR)/parse/validate_format.c \
		  $(SRC_DIR)/parse/parse_utils.c \
		  $(SRC_DIR)/parse/fill_map.c \
          $(GNL_DIR)/get_next_line.c

OBJS    = $(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I $(INC_DIR) -I $(LIBFT_DIR) -I $(GNL_DIR) -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx_Linux.a
	@echo "\033[32mLinking objects and creating $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(MLX) -o $(NAME)
	@echo "\033[32m$(NAME) successfully created!\033[0m"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@echo "\033[34mBuilding libft...\033[0m"
	@make -C $(LIBFT_DIR) > /dev/null 2>&1

$(MLX_DIR)/libmlx_Linux.a:
	@echo "\033[34mBuilding MinilibX...\033[0m"
	@make -C $(MLX_DIR) > /dev/null 2>&1

clean:
	@echo "\033[33mCleaning object files...\033[0m"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(MLX_DIR) clean > /dev/null 2>&1
	@echo "\033[32mClean completed successfully!\033[0m"

fclean: clean
	@echo "\033[33mRemoving $(NAME)...\033[0m"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@echo "\033[32mFull clean completed successfully!\033[0m"

re: fclean all

.PHONY: all clean fclean re
