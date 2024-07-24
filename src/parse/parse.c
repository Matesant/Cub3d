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
static char	**read_map(char *map);
static int	count_lines(char *map);
static void	replace_tabs_for_spaces(char *raw_data[]);

void	parse(t_game_essentials *game, char *map)
{
	game->map = malloc(sizeof(t_map));
	game->map->raw_data = read_map(map);
	replace_tabs_for_spaces(game->map->raw_data);
	get_textures(game,	 game->map->raw_data);
	get_colors(game, game->map->raw_data);
	get_map_matrice(game, game->map->raw_data);
	game->map->block_size = 16;
	printf("c: %d\n", game->map->ceiling_color);
	printf("f: %d\n", game->map->floor_color);
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
	matrice = ft_calloc(count + 1, sizeof (char *));
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
