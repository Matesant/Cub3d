#include "cub3d.h"

void	free_map(t_map *map)
{
	free(map->texture_path_NO);
	free(map->texture_path_SO);
	free(map->texture_path_WE);
	free(map->texture_path_EA);
	ft_delete_matrice(map->raw_data);
	ft_delete_matrice(map->map_matrice);
	free(map);
}


void	clear(t_game_essentials *game)
{
	if (game->map)
		free_map(game->map);
}

void	error(t_game_essentials *game, char *error_msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_msg, 2);
	clear(game);
	exit(EXIT_FAILURE);
}
