/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:22:05 by matesant          #+#    #+#             */
/*   Updated: 2024/07/19 16:44:14 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*replace(char *line);
static int	count_tabs(char *line);
static char	**ft_create_map(int fd);
static void	replace_tabs_for_spaces(char *raw_data[]);

void	parse(t_game_essentials *game, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	game->map = ft_calloc(1, sizeof(t_map));
	game->map->raw_data = ft_create_map(fd);
	close(fd);
	replace_tabs_for_spaces(game->map->raw_data);
	get_textures(game,	 game->map->raw_data);
	get_colors(game, game->map->raw_data);
	get_map_matrice(game, game->map->raw_data);
	game->map->block_size = 16;
}

static char	**ft_create_map(int fd)
{
	char	*line;
	char	*tmp_map;
	char	**finished_map;

	line = get_next_line(fd);
	tmp_map = ft_strdup("");
	while (line)
	{
		tmp_map = ft_strjoin_free(tmp_map, line);
		free(line);
		line = get_next_line(fd);
	}
	finished_map = ft_split(tmp_map, '\n');
	free(tmp_map);
	get_next_line(CLEAR_STATIC);
	return (finished_map);
}

static int	count_tabs(char *line)
{
	int count;

	count = 0;
	while (*line)
	{
		if (*line == '\t')
			count++;
		line++;
	}
	return (count);
}

static void	replace_tabs_for_spaces(char *raw_data[])
{
	int		line;
	char	*to_free;

	line = -1;
	while (raw_data[++line])
	{
		if (count_tabs(raw_data[line]) > 0)
		{
			to_free = raw_data[line];
			raw_data[line] = replace(raw_data[line]);
			free(to_free);
		}
	}
}

static char	*replace(char *line)
{
	int		replaced_len;
	char	*replaced;
	int		i;
	int		j;

	replaced_len = ft_strlen(line) + (count_tabs(line) * 4);
	replaced = ft_calloc(replaced_len, sizeof (char *));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			ft_memset(replaced + j, ' ', 4);
			j += 4;
			i++;
			continue ;
		}
		replaced[j] = line[i];
		i++;
		j++;
	}
	return (replaced);
}