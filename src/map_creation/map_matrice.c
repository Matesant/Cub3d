/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:22:05 by matesant          #+#    #+#             */
/*   Updated: 2024/07/18 18:26:36 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_create_map(int fd);

void	ft_print_matrice(char **matrice)
{
	int	i;
	int	j;

	i = 0;
	while (matrice[i])
	{
		j = 0;
		while (matrice[i][j])
		{
			write(1, &matrice[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

t_bool	ft_set_game_configs(char *map, t_game_essentials *game)
{
	int	fd;

	fd = open(map, O_RDONLY);
	game->map = (t_map *)malloc(sizeof(t_map));
	game->map->map_matrice = ft_create_map(fd);
	game->map->width = 19;
	game->map->height = 8;
	game->map->block_size = 12;
	close(fd);
	return (TRUE);
}

char	**ft_create_map(int fd)
{
	char	*line;
	char	*tmp_map;
	char	**finished_map;

	line = get_next_line(fd);
	tmp_map = ft_strdup("");
	while (line)
	{
		tmp_map = ft_strjoin_free(tmp_map, line);
		free(line);
		line = get_next_line(fd);
	}
	finished_map = ft_split(tmp_map, '\n');
	return (finished_map);
}
