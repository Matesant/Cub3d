/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:36:49 by matesant          #+#    #+#             */
/*   Updated: 2024/07/10 21:41:28 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_hooks(mlx_key_data_t key, void *param)
{
	t_game_essentials	*ptr;

	ptr = (t_game_essentials *)param;
	if (key.key == KEY_ESC)
	{
		mlx_terminate(ptr->mlx);
		exit(0);
	}
	if (key.key == KEY_W)
		ptr->player->y -= 5;
	if (key.key == KEY_S)
		ptr->player->y += 5;
	if (key.key == KEY_A)
		ptr->player->x -= 5;
	if (key.key == KEY_D)
		ptr->player->x += 5;
}
