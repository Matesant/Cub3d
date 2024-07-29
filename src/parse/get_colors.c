#include "cub3d.h"

static t_bool	is_color(char *line);
static uint32_t	get_rgb(int r, int g, int b);
static void	save_color(t_game_essentials *game, char *line);

void	get_colors(t_game_essentials *game, char **raw_data)
{
	int	line;
	int	count;

	line = -1;
	count = 0;
	while (raw_data[++line])
	{
		if (is_color(raw_data[line]))
		{
			save_color(game, raw_data[line]);
			count++;
		}
	}
	if (count != 2)
		error(game, "Wrong number of colors in map.\n");
	game->map->colors_obtained = TRUE;
}

static t_bool	is_color(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line == 'C' || *line == 'F')
		return (TRUE);
	return (FALSE);
}

static void	save_color(t_game_essentials *game, char *line)
{
	char	color_id;
	char	**rgb;
	char	**tmp;

	while (ft_isspace(*line))
		line++;
	color_id = *line;
	while (!ft_isdigit(*line))
		line++;
	rgb = ft_split(line, ',');
	if (ft_matrice_len(rgb) != 3)
		error(game, "Invalid color format\n");
	tmp = rgb;
	while (*tmp)
	{
		if (ft_atoi(*tmp) > 255 || ft_atoi(*tmp) < 0)
			error(game, "Invalid color range\n");
		tmp++;
	}
	if (color_id == 'F')
		game->map->floor_color = get_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
				ft_atoi(rgb[2]));
	if (color_id == 'C')
		game->map->ceiling_color = get_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
				ft_atoi(rgb[2]));
	ft_delete_matrice(rgb);
}

static uint32_t	get_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}
