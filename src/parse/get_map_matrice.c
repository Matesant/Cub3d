#include "cub3d.h"

t_bool is_map_matrice(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (ft_isdigit(*line))
		return (TRUE);
	else
		return (FALSE);
}

int get_matrice_lines_count(char **raw_data)
{
	int lines;

	lines = 0;
	while (raw_data[lines] && is_map_matrice(raw_data[lines]) == TRUE)
		lines++;
	return (lines);
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
	map_matrice = ft_calloc(lines_count + 1, sizeof(char *));
	line_index = -1;
	while (raw_data[++line_index])
		map_matrice[line_index] = ft_strdup(raw_data[line_index]);
	game->map->map_matrice = map_matrice;
}

t_bool	validade_map_matrice(char **map_matrice)
{
	int	line;
	int lines;
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

t_bool	is_open(t_game_essentials *game, char **matrice, int line, int column)
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

t_bool	check_closed_map(t_game_essentials *game)
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
			{
				printf("line: %d, column: %d\n", line, column);
				return (TRUE);
			}
		}
	}
	return (FALSE);
}


t_bool	check_map_is_last(char **raw_data)
{
	int	line;

	line = 0;
	while (raw_data[line] && is_map_matrice(raw_data[line]) == FALSE)
		line++;
	while (raw_data[line])
	{
		if (is_map_matrice(raw_data[line]) == FALSE && raw_data[line][0] != '\n')
			return (FALSE);
		line++;
	}
	return (TRUE);
}

void	get_map_matrice(t_game_essentials *game, char **raw_data)
{
	int	line;

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
		error(game, "Please provide a map matrice in your file\n");
	get_matrice_dimensions(game->map);
	if (!check_map_is_last(raw_data))
		error(game, "Map is not last content\n");
	if (!validade_map_matrice(game->map->map_matrice))
		error(game, "Invalid chars in your map matrice\n");
	if (check_closed_map(game))
		error(game, "Map is not closed\n");
}