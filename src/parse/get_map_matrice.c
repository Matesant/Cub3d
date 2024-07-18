#include "cub3d.h"

char	*is_map_matrice(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (ft_isdigit(*line))
		return (line);
	else
		return (NULL);
}

int	count_lines(char **raw_data)
{
	int	lines;

	lines = -1;
	while (raw_data[++lines])
		;
	return (lines);
}

void	copy_map(t_game_essentials *game, char **raw_data)
{
	char	**map_matrice;
	int		line_index;
	int		lines_count;

	lines_count = count_lines(raw_data);
	map_matrice = ft_calloc(lines_count, sizeof (char *));
	line_index = -1;
	while (raw_data[++line_index])
		map_matrice[line_index] = ft_strdup(raw_data[line_index]);
	game->map->map_matrice = map_matrice;
}

t_bool validade_map_matrice(t_game_essentials *game, char **raw_data)
{
	int		line_index;
	int		column_index;;

	line_index = -1;
	while (raw_data[++line_index])
	{
		column_index = -1;
		while (raw_data[line_index][++column_index])
		{
			if (!ft_strchr(" 01NSEW", raw_data[line_index][column_index]))
				return (FALSE);
		}
	}
	return (TRUE);
}

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
		if ((int) ft_strlen(matrice[height]) > width)
			width = ft_strlen(matrice[height]);
	}
	map->height = height;
	map->width = width;

}

void	get_map_matrice(t_game_essentials *game, char **raw_data)
{
	int	line;
	int	lines_count;

	line = -1;
	while (raw_data[++line])
	{
		if (is_map_matrice(raw_data[line]))
		{
			copy_map(game, raw_data + line);
			break ;
		}
	}
	if (game->map->map_matrice == NULL)
		error("Please provide a map matrice in your file\n");
	if (!validade_map_matrice(game, game->map->map_matrice))
		error("Invalid chars in your map matrice\n");
	get_matrice_dimensions(game->map);
}
