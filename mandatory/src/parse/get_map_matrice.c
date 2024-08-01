/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_matrice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:25:19 by almarcos          #+#    #+#             */
/*   Updated: 2024/07/31 02:00:53 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		crop_map(t_game_essentials *game, char **raw_data);
static t_bool	is_open(t_game_essentials *game, char **matrice, int line,
					int column);
static t_bool	check_closed_map(t_game_essentials *game);
static t_bool	check_map_is_last(char **raw_data);

void	get_map_matrice(t_game_essentials *game, char **raw_data)
{
	int	line;

	line = -1;
	while (raw_data[++line])
	{
		if (is_map_matrice(raw_data[line]))
		{
			crop_map(game, raw_data + line);
			break ;
		}
	}
	if (game->map->map_matrice == NULL)
		error(game, "Please provide a map matrice in your file\n");
	get_matrice_dimensions(game->map);
	if (!check_map_is_last(raw_data))
		error(game, "Map is not last content\n");
	if (!check_invalid_chars(game->map->map_matrice))
		error(game, "Invalid chars in your map matrice\n");
	if (check_closed_map(game))
		error(game, "Map is not closed\n");
	if (!check_player_position(game->map->map_matrice))
		error(game, "Invalid player position\n");
}

static void	crop_map(t_game_essentials *game, char **raw_data)
{
	char	**map_matrice;
	int		line;
	int		lines_count;

	lines_count = get_matrice_lines_count(raw_data);
	map_matrice = ft_calloc(lines_count + 1, sizeof(char *));
	line = -1;
	while (++line < lines_count)
		map_matrice[line] = ft_strdup(raw_data[line]);
	game->map->map_matrice = map_matrice;
}

static t_bool	is_open(t_game_essentials *game, char **matrice, int line,
		int column)
{
	if (matrice[line][column] == '0' || ft_strchr("NSEW",
			matrice[line][column]))
	{
		if (line == 0 || line == game->map->height - 1)
			return (TRUE);
		else if (column == 0 || column == game->map->width - 1)
			return (TRUE);
		else if (matrice[line - 1][column] == ' ' || (int)ft_strlen(matrice[line
				- 1]) < column)
			return (TRUE);
		else if (matrice[line + 1][column] == ' ' || (int)ft_strlen(matrice[line
				+ 1]) < column)
			return (TRUE);
		else if (matrice[line][column - 1] == ' ' || matrice[line][column
			+ 1] == ' ')
			return (TRUE);
	}
	return (FALSE);
}

static t_bool	check_closed_map(t_game_essentials *game)
{
	int		line;
	int		column;
	char	**matrice;

	line = -1;
	matrice = game->map->map_matrice;
	while (matrice[++line])
	{
		column = -1;
		while (matrice[line][++column])
		{
			if (is_open(game, matrice, line, column))
				return (TRUE);
		}
	}
	return (FALSE);
}

static t_bool	check_map_is_last(char **raw_data)
{
	int	line;

	line = 0;
	while (raw_data[line] && is_map_matrice(raw_data[line]) == FALSE)
		line++;
	while (raw_data[line])
	{
		if (is_map_matrice(raw_data[line]) == FALSE
			&& raw_data[line][0] != '\n')
			return (FALSE);
		line++;
	}
	return (TRUE);
}
