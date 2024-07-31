#include "cub3d.h"

void	free_map(t_map *map)
{
	free(map->texture_path_no);
	free(map->texture_path_so);
	free(map->texture_path_we);
	free(map->texture_path_ea);
	ft_delete_matrice(map->raw_data);
	ft_delete_matrice(map->map_matrice);
	free(map);
}

void	clear(t_game_essentials *game)
{
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);	
}

void	error(t_game_essentials *game, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	clear(game);
	exit(EXIT_FAILURE);
}

void	validade_argv(t_game_essentials *game, int argc, char **argv)
{
	char	*dot_position;

	if (argc != 2)
		error(game, "Please provide only a map file\n");
	dot_position = ft_strrchr(argv[1], '.');
	if (dot_position != NULL && ft_strcmp(dot_position + 1, "cub") == 0)
		return ;
	else
		error(game, "Invalid map extension\n");
}

