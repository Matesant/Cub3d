/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 06:37:59 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 06:38:45 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_cordinates(t_line *cordinates, int endx, int endy,
		t_player_pos *player)
{
	cordinates->deltax = ft_abs(endx - player->x);
	cordinates->deltay = -ft_abs(endy - player->y);
	cordinates->step_x = ft_compare_number(player->x, endx, 1);
	cordinates->step_y = ft_compare_number(player->y, endy, 1);
	cordinates->error_accumulated = cordinates->deltax + cordinates->deltay;
	cordinates->double_error = 0;
}
