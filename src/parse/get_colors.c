#include "cub3d.h"

t_bool		is_color(char *line);
void		save_color(t_game_essentials *game, char *line);
uint32_t	get_rgba(int r, int g, int b, int a);

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

t_bool	is_color(char *line)
{
	while (ft_isspace(*line))
		line++;
	if (*line == 'C' || *line == 'F')
		return (TRUE);
	return (FALSE);
}

void	save_color(t_game_essentials *game, char *line)
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
		game->map->floor_color = get_rgba(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]), 255);
	if (color_id == 'C')
		game->map->ceiling_color = get_rgba(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]), 255);
	ft_delete_matrice(rgb);
}

uint32_t	get_rgba(int r, int g, int b, int a)
{
	uint32_t	color;

	color = 0x000000;
	color |= r << 24;
	color |= g << 16;
	color |= b << 8;
	color |= 0b11111111;
	return (color);
}
