/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:54 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 04:01:21 by matesant         ###   ########.fr       */
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
		{
			break ;
		}
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
		{
			break ;
		}
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



void	ft_cast_rays(t_game_essentials *ptr, t_rays *ray)
{
	float	angle_diff;

	ray->angle = ft_normalize_angle(ray->angle);
	ft_cast_2d_horizontal_rays(ptr, ray);
	ft_cast_2d_vertical_rays(ptr, ray);
	if (ray->distance_horizontal < ray->distance_vertical)
	{
		ray->x = ray->distance_x_horizontal;
		ray->y = ray->distance_y_horizontal;
		ray->distance = ray->distance_horizontal;
		ray->axis = HORIZONTAL;
	}
	else
	{
		ray->x = ray->distance_x_vertical;
		ray->y = ray->distance_y_vertical;
		ray->distance = ray->distance_vertical;
		ray->axis = VERTICAL;
	}
	ft_put_line(ptr->img_map, ray->x, ray->y, ptr->player);
	ray->angle = ray->angle;
	angle_diff = cos(ptr->player->angle - ray->angle);
	ray->distance *= angle_diff;
}

void	ft_make_game(t_game_essentials *ptr)
{
	int x;
	float angle;

	x = 0;
	angle = ptr->player->angle - RAD * 30;
	while (x < WIDTH)
	{
		ptr->rays[x].angle = angle;
		ft_cast_rays(ptr, &ptr->rays[x]);
		ft_draw_wall(ptr, &ptr->rays[x], x);
		angle += STEP;
		x++;
	}
}
