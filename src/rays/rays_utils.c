/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:54 by matesant          #+#    #+#             */
/*   Updated: 2024/07/18 20:08:24 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initiate_rays(t_rays *rays)
{
	rays->amount = 0;
	rays->mapx = 0;
	rays->mapy = 0;
	rays->steps_to_obstacle = 0;
	rays->a_tan = 0;
	rays->x = 0;
	rays->y = 0;
	rays->angle = 0;
	rays->xoffset = 0;
	rays->yoffset = 0;
}

float	calculate_distance_to_wall(float player_x, float player_y, float wall_x,
		float wall_y, float angle)
{
	return (sqrt((wall_x - player_x) * (wall_x - player_x)) + (wall_y
			- player_y) * (wall_y - player_y));
}
void	ft_set_ray_x_y_horizontal(t_rays *ray, t_game_essentials *ptr)
{
	while (ray->steps_to_obstacle < 8)
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
				ray->distance_horizontal = calculate_distance_to_wall(ptr->player->x,
					ptr->player->y, ray->x, ray->y, ray->angle);
				return ;
			}
			else
			{
				ray->x += ray->xoffset;
				ray->y += ray->yoffset;
				ray->steps_to_obstacle++;
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
	while (ray->steps_to_obstacle < 8)
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
				ray->distance_vertical = calculate_distance_to_wall(ptr->player->x,
					ptr->player->y, ray->x, ray->y, ray->angle);
				return ;
			}
			else
			{
				ray->x += ray->xoffset;
				ray->y += ray->yoffset;
				ray->steps_to_obstacle++;
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

void	ft_cast_rays(t_game_essentials *ptr)
{
	t_rays	*ray;

	ray = malloc(sizeof(t_rays));
	ft_initiate_rays(ray);
	ray->angle = ptr->player->angle - RAD * 30;
	ray->angle = ft_normalize_angle(ray->angle);
	while (ray->amount++ < 100)
	{
		ft_cast_2d_horizontal_rays(ptr, ray);
		ft_cast_2d_vertical_rays(ptr, ray);
		if (ray->distance_horizontal < ray->distance_vertical)
		{
			ray->x = ray->distance_x_horizontal;
			ray->y = ray->distance_y_horizontal;
		}
		else if (ray->distance_horizontal > ray->distance_vertical)
		{
			ray->x = ray->distance_x_vertical;
			ray->y = ray->distance_y_vertical;
		}
		ft_put_line(ptr->img, ray->x, ray->y, ptr->player);
		ray->angle += RAD;
	}
	free(ray);
}
