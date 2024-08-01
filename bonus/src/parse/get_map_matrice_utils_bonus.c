/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_matrice_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:27:58 by almarcos          #+#    #+#             */
/*   Updated: 2024/08/01 16:18:05 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_matrice_dimensions(t_map *map)
{
	char	**matrice;
	int		width;
	int		height;

	width = -1;
	height = -1;
	matrice = map->map_matrice;
	while (matrice[++height])
	{
		if ((int)ft_strlen(matrice[height]) > width)
			width = ft_strlen(matrice[height]);
	}
	map->height = height;
	map->width = width;
}

int	get_matrice_lines_count(char **raw_data)
{
	int	lines;

	lines = 0;
	while (raw_data[lines] && is_map_matrice(raw_data[lines]) == TRUE)
		lines++;
	return (lines);
}

t_bool	is_map_matrice(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (ft_isdigit(*line))
		return (TRUE);
	else
		return (FALSE);
}

t_bool	check_invalid_chars(char **map_matrice)
{
	int	line;
	int	lines;
	int	column;

	line = 0;
	lines = get_matrice_lines_count(map_matrice);
	while (map_matrice[line] && line < lines)
	{
		column = -1;
		while (map_matrice[line][++column])
		{
			if (!ft_strchr(" 01NSEW", map_matrice[line][column]))
				return (FALSE);
		}
		line++;
	}
	return (TRUE);
}

t_bool	check_player_position(char **map_matrice)
{
	int	player_count;
	int	line;
	int	column;

	player_count = 0;
	line = 0;
	while (map_matrice[line])
	{
		column = 0;
		while (map_matrice[line][column])
		{
			if (ft_strchr("NSEW", map_matrice[line][column]))
				player_count++;
			column++;
		}
		line++;
	}
	if (player_count != 1)
		return (FALSE);
	else
		return (TRUE);
}
