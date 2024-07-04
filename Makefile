CC          := cc
NAME        := cub3d
CFLAGS      := -Wall -Werror -Wextra -g3 -O0
LIBMLX      := MLX42
MLX_REPO    := https://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@github.com/Matesant/MLX.git
TOKEN       := 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
MLX         := $(LIBMLX)/build/libmlx42.a
BIN         := ./bin/
HEADER      := ./include/ $(LIBMLX)/include
LIBS        := $(MLX) -ldl -lglfw -pthread -lm
PRINTF      := ./libft/Printf/libftprintf.a
LIBFT       := ./libft/libft.a
42LIBS      := $(PRINTF) $(LIBFT)
SOURCE      := main.c

OBJECTS     := $(addprefix $(BIN),$(SOURCE:.c=.o))

BLUE        := \033[1;34m
RED         := \033[0;31m
GREEN       := \033[0;32m
END         := \033[0m

.PHONY: all clean fclean re val mlx

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

$(BIN)%.o: ./src/%.c $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $<...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJECTS) $(HEADER)
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@printf "$(BLUE)Compiling $(NAME)...$(END)\n"
	@printf "$(BLUE)-----------------------------------------------$(END)\n"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIBS)
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
	cd $(LIBMLX) && cmake -B build && cmake --build build -j4

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
	@rm -rf $(LIBMLX)
	@printf "$(GREEN)All cleaned!$(END)\n"

re: fclean all

val:
