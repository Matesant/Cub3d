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

void	ft_pre_verifications(int argc, char **argv)
{
	char *dot_position;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error\nPlease provide a map file\n", 2);
		exit(EXIT_FAILURE);
	}
	dot_position = ft_strrchr(argv[1], '.');
	if (dot_position != NULL && ft_strcmp(dot_position + 1, "cub") == 0)
		return ;
	else
	{
		ft_putstr_fd("Error\nInvalid map extension\n", 2);
		exit(EXIT_FAILURE);
	}
}
