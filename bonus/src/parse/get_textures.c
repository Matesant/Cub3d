/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 02:03:38 by almarcos          #+#    #+#             */
/*   Updated: 2024/07/31 02:03:39 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture(t_game_essentials *game, char *line, char **dest_to_put)
{
	while (ft_isspace(*line))
		line++;
	line += 2;
	while (ft_isspace(*line))
		line++;
	if (*line == '\0' || *dest_to_put != NULL)
		error(game, "Path for one or more textures is missing.\n");
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
			count += get_texture(game, raw_data[line],
					&game->map->texture_path_no);
		else if (is_this_texture("SO ", raw_data[line]))
			count += get_texture(game, raw_data[line],
					&game->map->texture_path_so);
		else if (is_this_texture("EA ", raw_data[line]))
			count += get_texture(game, raw_data[line],
					&game->map->texture_path_ea);
		else if (is_this_texture("WE ", raw_data[line]))
			count += get_texture(game, raw_data[line],
					&game->map->texture_path_we);
	}
	if (count != 4)
		error(game, "Invalid number of textures\n");
	game->map->textures_obtained = TRUE;
}
