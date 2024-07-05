/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:22:05 by matesant          #+#    #+#             */
/*   Updated: 2024/07/05 14:57:22 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_create_map(char **map, int fd);

void ft_print_matrice(char **matrice)
{
	int i;
	int j;

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

t_bool ft_set_game_configs(char *map, t_game_essentials *game)
{
	int fd;
	
	fd = open(map, O_RDONLY);
	ft_create_map(game->map_matrice, fd);
	return (TRUE);
}

void ft_create_map(char **map, int fd)
{
	char *line;
	char *tmp_map;

	get_next_line(-1);
	line = get_next_line(fd);
	tmp_map = NULL;
	while(line)
	{
		tmp_map = ft_strjoin(tmp_map, line);
		line = get_next_line(fd);
	}
	map = ft_split(tmp_map, '\n');
	ft_print_matrice(map);
}
