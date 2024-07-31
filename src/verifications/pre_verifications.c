/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_verifications.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:54:23 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 19:24:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validade_argv(t_game_essentials *game, int argc, char **argv)
{
	char	*dot_position;

	if (argc != 2)
		error(game, "Please provide only a map file\n");
	dot_position = ft_strrchr(argv[1], '.');
	if (dot_position != NULL && ft_strcmp(dot_position + 1, "cub") == 0)
		return ;
	else
		error(game, "Invalid map extension\n");
}
