/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_verifications.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:54:23 by matesant          #+#    #+#             */
/*   Updated: 2024/07/03 22:13:40 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	ft_check_map_extension(char **map);

t_bool	ft_pre_verifications(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments.\n");
		return (TRUE);
	}
	if (ft_check_map_extension(argv))
		return (TRUE);
	return (FALSE);
}

t_bool	ft_check_map_extension(char **map)
{
	int	argv_index;
	int	map_name_size;

	argv_index = 1;
	map_name_size = ft_strlen(map[argv_index]);
	if (map[argv_index][map_name_size - 1] != 'b'
		|| map[argv_index][map_name_size - 2] != 'u'
		|| map[argv_index][map_name_size - 3] != 'c'
		|| map[argv_index][map_name_size - 4] != '.')
	{
		printf("Error\nMap extension is not valid.\n");
		return (TRUE);
	}
	return (FALSE);
}
