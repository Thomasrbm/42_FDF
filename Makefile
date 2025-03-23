# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: throbert <throbert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 19:09:36 by throbert          #+#    #+#              #
#    Updated: 2025/03/23 16:32:04 by throbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -O3 -march=native -flto -funroll-loops -ftree-vectorize -fomit-frame-pointer

# ================================
# === LIBFT & MINILIBX CONFIG ===
# ================================
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_REPO = https://github.com/Thomasrbm/42_Turbo-Lib.git

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

# ========================
# === FILE STRUCTURE ====
# ========================
SRC_DIR = fdf_dir
GNL_DIR = gnl
OBJ_DIR = objs

SRCS = $(wildcard $(SRC_DIR)/*.c) \
	   $(wildcard $(SRC_DIR)/draw/*.c) \
	   $(wildcard $(SRC_DIR)/events/*.c) \
	   $(wildcard $(SRC_DIR)/parse/*.c) \
	   $(wildcard $(GNL_DIR)/*.c)

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I $(LIBFT_DIR) -I $(MLX_DIR)
FULL_CFLAGS = $(CFLAGS) $(INCLUDES)

# ========================
# === COLORS ============
# ========================
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

# =====================
# === ALL TARGET ====
# =====================
all: $(LIBFT) $(MLX) $(NAME)

# ==========================
# === LIBFT AUTOMATIQUE ===
# ==========================
$(LIBFT):
	@echo "$(BLUE)Téléchargement de la libft depuis $(LIBFT_REPO)...$(RESET)"
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	else \
		echo "$(BLUE)Libft déjà présente, mise à jour...$(RESET)"; \
		cd $(LIBFT_DIR) && git pull; \
	fi
	@echo "$(BLUE)Compilation de la libft...$(RESET)"
	@make -C $(LIBFT_DIR) > /dev/null
	@echo "$(GREEN)Libft compilée avec succès !$(RESET)"

# ==============================
# === MINILIBX AUTOMATIQUE ====
# ==============================
$(MLX):
	@echo "$(BLUE)Téléchargement de la minilibx depuis $(MLX_REPO)...$(RESET)"
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	else \
		echo "$(BLUE)Minilibx déjà présente, mise à jour...$(RESET)"; \
		cd $(MLX_DIR) && git pull; \
	fi
	@echo "$(BLUE)Compilation de la minilibx...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null
	@echo "$(GREEN)Minilibx compilée avec succès !$(RESET)"

# ==========================
# === FICHIERS OBJETS ====
# ==========================
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)Compilation de $<...$(RESET)"
	@$(CC) $(FULL_CFLAGS) -c $< -o $@

# =====================
# === COMPILATION ====
# =====================
$(NAME): $(OBJS) $(LIBFT)
	@echo "$(YELLOW)Création de l'exécutable $(NAME)...$(RESET)"
	@$(CC) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
	@echo "$(GREEN)Compilation de $(NAME) terminée avec succès !$(RESET)"
	@echo "$(BLUE)"
	@echo "   ...   ...   ...  .,lll;.''.  .'.   ',.  .',.  .',...,coc....;'.  .;'. ..;'. .;lc'...',."
	@echo "   .'.   ...   .'.   .'';llc;.  .'.   ',.   ',.   ',.  ..clc;..;'   .,'   .;'   .;::;,.,,."
	@echo " .   .'.   .'.   .'.   .'...;loc,.',.  .',.   ';.  .';.  ..;,,:ccc,....;'. ..;'....;,.,::c"
	@echo "$(RESET)"

# ======================
# === CLEAN TARGETS ===
# ======================
clean:
	@echo "$(RED)Suppression des fichiers objets...$(RESET)"
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean > /dev/null || true
	@make -C $(MLX_DIR) clean > /dev/null || true
	@echo "$(GREEN)Nettoyage terminé !$(RESET)"

# ========================
# === FCLEAN TARGETS ====
# ========================
fclean: clean
	@echo "$(RED)Suppression de l'exécutable $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then \
		echo "$(RED)Suppression du dossier libft...$(RESET)"; \
		rm -rf $(LIBFT_DIR); \
	fi
	@if [ -d "$(MLX_DIR)" ]; then \
		echo "$(RED)Suppression du dossier minilibx...$(RESET)"; \
		rm -rf $(MLX_DIR); \
	fi
	@echo "$(GREEN)Nettoyage complet terminé !$(RESET)"

# ====================
# === REBUILD ========
# ====================
re: fclean all

# ==========================
# === PHONY RULES ==========
# ==========================
.PHONY: all clean fclean re
