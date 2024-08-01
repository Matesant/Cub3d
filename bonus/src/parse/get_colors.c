/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 01:43:17 by almarcos          #+#    #+#             */
/*   Updated: 2024/07/31 02:25:09 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgb(char **rgb);
static t_bool	is_color(char *line);
static t_bool	check_color_range(char **rgb);
static void		save_color(t_game_essentials *game, char *line);

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

static t_bool	check_color_range(char **rgb)
{
	while (*rgb)
	{
		if (ft_atoi(*rgb) < 0 || ft_atoi(*rgb) > 255)
			return (FALSE);
		rgb++;
	}
	return (TRUE);
}

static void	save_color(t_game_essentials *game, char *line)
{
	char	color_id;
	char	**rgb;

	while (ft_isspace(*line))
		line++;
	color_id = *line;
	while (!ft_isdigit(*line))
		line++;
	rgb = ft_split(line, ',');
	if (ft_matrice_len(rgb) != 3 || !check_color_range(rgb))
	{
		ft_delete_matrice(rgb);
		error(game, "Invalid colors\n");
	}
	if (color_id == 'F')
		game->map->floor_color = get_rgb(rgb);
	if (color_id == 'C')
		game->map->ceiling_color = get_rgb(rgb);
	ft_delete_matrice(rgb);
}

static uint32_t	get_rgb(char **rgb)
{
	uint32_t	color;

	color = ft_atoi(rgb[0]) << 24;
	color |= ft_atoi(rgb[1]) << 16;
	color |= ft_atoi(rgb[2]) << 8;
	color |= 0x000000ff;
	return (color);
}
