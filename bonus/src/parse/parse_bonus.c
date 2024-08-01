/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:07:00 by matesant          #+#    #+#             */
/*   Updated: 2024/08/01 16:18:13 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static char	**read_map(char *map);
static int	count_lines(char *map);

void	parse(t_game_essentials *game, char *map)
{
	game->map = ft_calloc(1, sizeof(t_map));
	game->map->raw_data = read_map(map);
	replace_tabs_for_spaces(game->map->raw_data);
	get_textures(game, game->map->raw_data);
	get_colors(game, game->map->raw_data);
	get_map_matrice(game, game->map->raw_data);
	game->map->block_size = 16;
	load_textures(game);
}

static int	count_lines(char *map)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(map, O_RDONLY);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	close(fd);
	get_next_line(CLEAR_STATIC);
	return (count);
}

static char	**read_map(char *map)
{
	char	**matrice;
	int		count;
	char	*line;
	int		index;
	int		fd;

	count = count_lines(map);
	matrice = ft_calloc(count + 1, sizeof(char *));
	fd = open(map, O_RDONLY);
	index = -1;
	while (++index < count)
	{
		line = get_next_line(fd);
		if (line[0] == '\n')
			matrice[index] = line;
		else
		{
			matrice[index] = ft_strtrim(line, "\n");
			free(line);
		}
	}
	close(fd);
	get_next_line(CLEAR_STATIC);
	return (matrice);
}
