/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:11:36 by matesant          #+#    #+#             */
/*   Updated: 2024/07/17 21:27:14 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cast_2d_rays(t_game_essentials *ptr)
{
	t_rays	*ray;

	ray->angle = ptr->player->angle;
	if (ray->amount < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	for (r = 0; r < NUM_RAYS; r++)
	{
		dof = 0;
		aTan = -1 / tan(ra);
		if (ra > PI) // Raio aponta para cima
		{
			ry = (((int)ptr->player->y / ptr->map->block_size)
					* ptr->map->block_size) - 0.0001;
			rx = (ptr->player->y - ry) * aTan + ptr->player->x;
			yo = -ptr->map->block_size;
			xo = -yo * aTan;
		}
		else if (ra < PI) // Raio aponta para baixo
		{
			ry = (((int)ptr->player->y / ptr->map->block_size)
					* ptr->map->block_size) + ptr->map->block_size;
			rx = (ptr->player->y - ry) * aTan + ptr->player->x;
			yo = ptr->map->block_size;
			xo = -yo * aTan;
		}
		else // Raio horizontal (direita ou esquerda)
		{
			rx = ptr->player->x;
			ry = ptr->player->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) / ptr->map->block_size;
			my = (int)(ry) / ptr->map->block_size;
			if (my >= 0 && my < ptr->map->height && mx >= 0
				&& mx < ptr->map->width)
			{
				if (ptr->map->map_matrice[my][mx] == '1')
				{
					dof = 8; // Pare quando encontrar uma parede
				}
				else
				{
					rx += xo;
					ry += yo;
					dof++;
				}
			}
			else
			{
				break ; // Saia do loop se sair dos limites do mapa
			}
		}
		// Desenhar o raio no mapa (opcional)
		ft_put_line(ptr->img, rx, ry, ptr->player);
	}
}
