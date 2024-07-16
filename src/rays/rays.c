/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:11:36 by matesant          #+#    #+#             */
/*   Updated: 2024/07/16 18:07:40 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1,
		int color)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		mlx_put_pixel(img, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	ft_cast_2d_rays(t_game_essentials *ptr)
{
	float	aTan;

	int r, mx, my, mp, dof;
	float rx, ry, ra, xo, yo;
	ra = ptr->player->angle;
	if (ra < 0)
		ra += 2 * PI;
	if (ra > 2 * PI)
		ra -= 2 * PI;
	for (r = 0; r < NUM_RAYS; r++)
	{
		dof = 0;
		aTan = -1 / tan(ra);
		if (ra > PI)
		{
			ry = (((int)ptr->player->y >> 6) << 6) - 0.0001;
			rx = (ptr->player->y - ry) * aTan + ptr->player->x;
			yo = -64;
			xo = -yo * aTan;
		}
		else if (ra < PI)
		{
			ry = (((int)ptr->player->y >> 6) << 6) + 64;
			rx = (ptr->player->y - ry) * aTan + ptr->player->x;
			yo = 64;
			xo = -yo * aTan;
		}
		else
		{
			rx = ptr->player->x;
			ry = ptr->player->y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			if (my >= 0 && my < ptr->map->height && mx >= 0
				&& mx < ptr->map->width)
			{
				mp = my * ptr->map->width + mx;
				if (ptr->map->map_matrice[my][mx] == '1')
				{
					dof = 8;
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
				break ; // Saída do loop se o índice estiver fora dos limites
			}
		}
		// Desenhar o raio no mapa (opcional)
		ft_draw_line(ptr->img, ptr->player->x, ptr->player->y, rx, ry,
			0xFFFFFF00);
	}
}
