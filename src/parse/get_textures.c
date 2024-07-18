#include "cub3d.h"

static int	get_texture(t_game_essentials *game, char *line, char **dest_to_put)
{
	while (ft_isspace(*line))
		line++;
	line += 2;
	while (ft_isspace(*line))
		line++;
	if (*line == '\0')
		error(game, "You not provide path for some texture\n");
	*dest_to_put = ft_strdup(line);
	return (1);
}

static t_bool	is_this_texture(char *texture, char *line)
{
	while (ft_isspace(*line))
		line++;
	if (ft_strncmp(line, texture, 3) == 0)
		return (TRUE);
	return (FALSE);
}

void	get_textures(t_game_essentials *game, char **raw_data)
{
	int	line;
	int	count;

	line = -1;
	count = 0;
	while (raw_data[++line])
	{
		if (is_this_texture("NO ", raw_data[line]))
			 count += get_texture(game, raw_data[line], &game->map->texture_path_NO);
		else if (is_this_texture("SO ", raw_data[line]))
			 count += get_texture(game, raw_data[line], &game->map->texture_path_SO);
		else if (is_this_texture("EA ", raw_data[line]))
			 count += get_texture(game, raw_data[line], &game->map->texture_path_EA);
		else if (is_this_texture("WE ", raw_data[line]))
			 count += get_texture(game, raw_data[line], &game->map->texture_path_WE);
	}
	if (count != 4 ||
		game->map->texture_path_EA == NULL ||
		game->map->texture_path_NO == NULL ||
		game->map->texture_path_SO == NULL ||
		game->map->texture_path_WE == NULL)
		error(game, "Invalid number of textures\n");
	game->map->textures_obtained = TRUE;
}
