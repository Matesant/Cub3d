CC          := cc
NAME        := cub3d
CFLAGS      := -Wall -Werror -Wextra -O0 -g3
LIBMLX      := MLX42
MLX_REPO    := https://github.com/Matesant/MLX42
MLX         := $(LIBMLX)/build/libmlx42.a
BIN         := ./bin/
INCLUDES    := -I./include -I$(LIBMLX)/include
LIBS        := $(MLX) -ldl -lglfw -pthread -lm
PRINTF      := ./libft/Printf/libftprintf.a
LIBFT       := ./libft/libft.a
42LIBS      := $(PRINTF) $(LIBFT)
SOURCE      := main.c parse.c utils.c get_textures.c get_colors.c \
				get_map_matrice.c key_hooks.c loop_hooks.c draw_images.c init_mlx.c \
				draw_line.c draw_line_utils.c horizontal_rays.c vertical_rays.c rays_utils.c \
				load_textures.c get_cardinal_direction.c key_utils.c movement_keys.c draw_wall.c \

OBJECTS     := $(addprefix $(BIN),$(SOURCE:.c=.o))

BLUE        := \033[1;34m
RED         := \033[0;31m
GREEN       := \033[0;32m
END         := \033[0m

.PHONY: all clean fclean re val

all: $(42LIBS) $(BIN) $(NAME)

$(LIBFT):
	@printf "$(BLUE)----------------------$(END)\n"
	@printf "$(BLUE)--Compiling Libft...-$(END)\n"
	@printf "$(BLUE)----------------------$(END)\n"
	@make -C ./libft --no-print-directory

$(PRINTF):
	@printf "$(BLUE)----------------------$(END)\n"
	@printf "$(BLUE)-Compiling Printf...-$(END)\n"
	@printf "$(BLUE)----------------------$(END)\n"
	@make -C ./libft/Printf --no-print-directory

$(BIN):
	@mkdir -p $(BIN)

$(BIN)%.o: ./src/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./src/verifications/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./src/parse/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./src/hooks/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./src/image/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./src/draw_line/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./src/setup_environment/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN)%.o: ./src/rays/%.c
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJECTS)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $(NAME)...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS) $(42LIBS) $(LIBS) -o $(NAME)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(GREEN)--$(NAME) compiled!-$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"

mlx:
	@if [ -d "$(LIBMLX)" ]; then \
		echo "O diretório $(LIBMLX) já existe."; \
	else \
		echo "Clonando repositório..."; \
		git clone $(MLX_REPO) $(LIBMLX); \
	fi
	@printf "$(BLUE)----------------------$(END)\n"
	@printf "$(BLUE)--Building MLX...-$(END)\n"
	@printf "$(BLUE)----------------------$(END)\n"
	cd $(LIBMLX) && cmake -B build
	cd $(LIBMLX) && cmake --build build -j4

clean:
	@printf "$(RED)Cleaning...$(END)\n"
	@make -C ./libft/Printf clean --no-print-directory
	@make -C ./libft clean --no-print-directory
	@rm -rf $(BIN)

fclean: clean
	@printf "$(RED)Cleaning...$(END)\n"
	@make -C ./libft/Printf --no-print-directory fclean
	@make -C ./libft --no-print-directory fclean
	@rm -rf $(NAME)
	@printf "$(GREEN)All cleaned!$(END)\n"

val:
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=./sup.sup ./cub3d assets/maps/minecraft_lib.cub

re: fclean all

val:
