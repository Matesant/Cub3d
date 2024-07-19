/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:30:55 by matesant          #+#    #+#             */
/*   Updated: 2024/07/19 15:37:41 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_if_angle_is_looking_left(t_rays *ray, t_game_essentials *ptr,
		float n_tan)
{
	if (ray->angle > P2 && ray->angle < P3)
	{
		ray->x = (((int)ptr->player->x / ptr->map->block_size)
			* ptr->map->block_size) - 0.0001;
		ray->y = (ptr->player->x - ray->x) * n_tan + ptr->player->y;
		ray->xoffset = -ptr->map->block_size;
		ray->yoffset = -ray->xoffset * n_tan;
	}
}

void	ft_set_if_angle_is_looking_right(t_rays *ray, t_game_essentials *ptr,
		float n_tan)
{
	if (ray->angle < P2 || ray->angle > P3)
	{
		ray->x = (((int)ptr->player->x / ptr->map->block_size)
			* ptr->map->block_size) + ptr->map->block_size;
		ray->y = (ptr->player->x - ray->x) * n_tan + ptr->player->y;
		ray->xoffset = ptr->map->block_size;
		ray->yoffset = -ray->xoffset * n_tan;
	}
}

void	ft_cast_2d_vertical_rays(t_game_essentials *ptr, t_rays *ray)
{
	float	n_tan;

	ray->distance_vertical = 100000;
	ray->distance_x_vertical = ptr->player->x;
	ray->distance_y_vertical = ptr->player->y;
	ray->steps_to_obstacle = 0;
	n_tan = -tan(ray->angle);
	ft_set_if_angle_is_looking_left(ray, ptr, n_tan);
	ft_set_if_angle_is_looking_right(ray, ptr, n_tan);
	if (ft_fabs(ray->angle) < EPSILON || ft_fabs(ray->angle - PI) < EPSILON)
	{
		ray->x = ptr->player->x;
		ray->y = ptr->player->y;
		ray->steps_to_obstacle = 8;
	}
	ft_set_ray_x_y_vertical(ray, ptr);
}
