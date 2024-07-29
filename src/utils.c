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
