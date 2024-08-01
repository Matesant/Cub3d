/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:21:58 by almarcos          #+#    #+#             */
/*   Updated: 2024/07/31 02:38:29 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		i;

	i = 0;
	if (game->map)
		free_map(game->map);
	if (game->player)
		free(game->player);
	i = -1;
	while (++i < 4)
		mlx_delete_texture(game->textures[i]);
}

void	error(t_game_essentials *game, char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	clear(game);
	exit(EXIT_FAILURE);
}

void	validade_argv(t_game_essentials *game, int argc, char **argv)
{
	char	*dot_position;
	int		fd;

	if (argc != 2)
		error(game, "Please provide only a map file\n");
	dot_position = ft_strrchr(argv[1], '.');
	if (dot_position != NULL && ft_strcmp(dot_position, ".cub") != 0)
		error(game, "Invalid map extension\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error(game, "No read permition for map\n");
	close(fd);
}
