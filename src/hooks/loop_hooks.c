/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:37:43 by matesant          #+#    #+#             */
/*   Updated: 2024/07/19 16:46:30 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hook(void *param)
{
	t_game_essentials	*ptr;

	ptr = (t_game_essentials *)param;
	ft_draw_map(ptr, ptr->map->block_size);
	ft_put_player(ptr->img, ptr->player);
	ft_cast_rays(ptr);
}
