CC          := cc
NAME        := cub3d
NAME_BONUS  := cub3d_bonus
CFLAGS      := -Wall -Werror -Wextra -O0 -g3
MLX         := ./libs/MLX42/build/libmlx42.a
BIN         := ./bin/
INCLUDES    := -I./mandatory/include -I./libs/MLX42/include
INCLUDES_BONUS := -I./bonus/include -I./libs/MLX42/include
MLX_LIBS    := $(MLX) -ldl -lglfw -pthread -lm
PRINTF      := ./libs/libft/Printf/libftprintf.a
LIBFT       := ./libs/libft/libft.a
42LIBS      := $(PRINTF) $(LIBFT)
SOURCE      := main.c parse.c utils.c get_textures.c get_colors.c \
				get_map_matrice.c key_hooks.c loop_hooks.c draw_images.c inits.c \
				draw_line.c draw_line_utils.c horizontal_rays.c vertical_rays.c rays_utils.c \
				load_textures.c get_cardinal_direction.c key_hooks_utils.c movement_keys.c draw_wall.c \
				get_map_matrice_utils.c replace_tabs.c

SOURCE_BONUS := main_bonus.c parse_bonus.c utils_bonus.c get_textures_bonus.c get_colors_bonus.c \
				get_map_matrice_bonus.c key_hooks_bonus.c loop_hooks_bonus.c draw_images_bonus.c inits_bonus.c \
				draw_line_bonus.c draw_line_utils_bonus.c horizontal_rays_bonus.c vertical_rays_bonus.c rays_utils_bonus.c \
				load_textures_bonus.c get_cardinal_direction_bonus.c key_hooks_utils_bonus.c movement_keys_bonus.c draw_wall_bonus.c \
				get_map_matrice_utils_bonus.c replace_tabs_bonus.c mouse_bonus.c

OBJECTS     := $(addprefix $(BIN),$(SOURCE:.c=.o))

OBJECTS_BONUS     := $(addprefix $(BIN),$(SOURCE_BONUS:.c=.o))

BLUE        := \033[1;34m
RED         := \033[0;31m
GREEN       := \033[0;32m
END         := \033[0m

.PHONY: all clean fclean re val bonus re_bonus

all: $(LIBFT) $(PRINTF) $(MLX) $(BIN) $(NAME)

$(LIBFT):
	@printf "$(BLUE)----------------------$(END)\n"
	@printf "$(BLUE)--Compiling Libft...-$(END)\n"
	@printf "$(BLUE)----------------------$(END)\n"
	@make -C ./libs/libft --no-print-directory

$(PRINTF):
	@printf "$(BLUE)----------------------$(END)\n"
	@printf "$(BLUE)-Compiling Printf...-$(END)\n"
	@printf "$(BLUE)----------------------$(END)\n"
	@make -C ./libs/libft/Printf --no-print-directory

$(BIN):
	@mkdir -p $(BIN)

$(BIN)%.o: ./mandatory/src/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./mandatory/src/verifications/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./mandatory/src/parse/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./mandatory/src/hooks/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./mandatory/src/image/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./mandatory/src/draw_line/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./mandatory/src/inits/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./mandatory/src/ray_cast/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJECTS)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $(NAME)...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(42LIBS) $(MLX_LIBS) -o $(NAME)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(GREEN)--$(NAME) compiled!-$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"

$(BIN)%.o: ./bonus/src/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

$(BIN)%.o: ./bonus/src/verifications/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

$(BIN)%.o: ./bonus/src/parse/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

$(BIN)%.o: ./bonus/src/hooks/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

$(BIN)%.o: ./bonus/src/image/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

$(BIN)%.o: ./bonus/src/draw_line/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

$(BIN)%.o: ./bonus/src/inits/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

$(BIN)%.o: ./bonus/src/ray_cast/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $(NAME_BONUS)...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(42LIBS) $(MLX_LIBS) -o $(NAME_BONUS)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(GREEN)--$(NAME_BONUS) compiled!-$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"

$(MLX):
	@cmake ./libs/MLX42/ -B ./libs/MLX42/build/ && make -C ./libs/MLX42/build -j4

bonus: $(LIBFT) $(PRINTF) $(MLX) $(BIN) $(NAME_BONUS)

clean:
	@printf "$(RED)Cleaning...$(END)\n"
	@make -C ./libs/libft/Printf clean --no-print-directory
	@make -C ./libs/libft clean --no-print-directory
	@rm -rf ./libs/MLX42/build
	@rm -rf $(BIN)

fclean: clean
	@printf "$(RED)Full cleaning...$(END)\n"
	@make -C ./libs/libft/Printf --no-print-directory fclean
	@make -C ./libs/libft --no-print-directory fclean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@printf "$(GREEN)All cleaned!$(END)\n"

val:
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=./sup.sup ./cub3d assets/maps/minecraft_lib.cub

re: fclean all

re_bonus: fclean bonus

val:
