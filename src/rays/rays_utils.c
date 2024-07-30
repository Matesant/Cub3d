/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:54 by matesant          #+#    #+#             */
/*   Updated: 2024/07/30 13:58:18 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_ray_x_y_horizontal(t_rays *ray, t_game_essentials *ptr)
{
	while (1)
	{
		ray->mapx = (int)(ray->x) / ptr->map->block_size;
		ray->mapy = (int)(ray->y) / ptr->map->block_size;
		if (ray->mapy >= 0 && ray->mapy < ptr->map->height && ray->mapx >= 0
			&& ray->mapx < ptr->map->width)
		{
			if (ptr->map->map_matrice[ray->mapy][ray->mapx] == '1')
			{
				ray->distance_x_horizontal = ray->x;
				ray->distance_y_horizontal = ray->y;
				ray->distance_horizontal = hypot(ptr->player->x - ray->x,
						ptr->player->y - ray->y);
				return ;
			}
			else
			{
				ray->x += ray->xoffset;
				ray->y += ray->yoffset;
			}
		}
		else
			break ;
	}
}

void	ft_set_ray_x_y_vertical(t_rays *ray, t_game_essentials *ptr)
{
	while (1)
	{
		ray->mapx = (int)(ray->x) / ptr->map->block_size;
		ray->mapy = (int)(ray->y) / ptr->map->block_size;
		if (ray->mapy >= 0 && ray->mapy < ptr->map->height && ray->mapx >= 0
			&& ray->mapx < ptr->map->width)
		{
			if (ptr->map->map_matrice[ray->mapy][ray->mapx] == '1')
			{
				ray->distance_x_vertical = ray->x;
				ray->distance_y_vertical = ray->y;
				ray->distance_vertical = hypot(ptr->player->x - ray->x,
						ptr->player->y - ray->y);
				return ;
			}
			else
			{
				ray->x += ray->xoffset;
				ray->y += ray->yoffset;
			}
		}
		else
			break ;
	}
}

float	ft_normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	ft_cast_rays(t_game_essentials *ptr, t_rays *rays)
{
	float	angle_diff;

	rays->angle = ft_normalize_angle(rays->angle);
	ft_cast_2d_horizontal_rays(ptr, rays);
	ft_cast_2d_vertical_rays(ptr, rays);
	if (rays->distance_horizontal < rays->distance_vertical)
	{
		rays->x = rays->distance_x_horizontal;
		rays->y = rays->distance_y_horizontal;
		rays->distance = rays->distance_horizontal;
		rays->axis = HORIZONTAL;
	}
	else
	{
		rays->x = rays->distance_x_vertical;
		rays->y = rays->distance_y_vertical;
		rays->distance = rays->distance_vertical;
		rays->axis = VERTICAL;
	}
	//ft_draw_ray(ptr, rays);
	angle_diff = cos(ptr->player->angle - rays->angle);
	rays->distance *= angle_diff;
}

void	ft_make_game(t_game_essentials *ptr)
{
	int		x;
	float	angle;
	t_rays	rays;

	ft_bzero(&rays, sizeof(t_rays));
	x = 0;
	angle = ptr->player->angle - RAD * 30;
	while (x < WIDTH)
	{
		rays.angle = angle;
		ft_cast_rays(ptr, &rays);
		ft_draw_wall(ptr, &rays, x);
		angle += STEP;
		x++;
	}
}
