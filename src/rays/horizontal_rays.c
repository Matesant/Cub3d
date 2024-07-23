/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:11:36 by matesant          #+#    #+#             */
/*   Updated: 2024/07/23 12:25:20 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_if_angle_is_looking_up(t_rays *ray, t_game_essentials *ptr,
		float a_tan)
{
	if (ray->angle > PI)
	{
		ray->y = (((int)ptr->player->y >> 4) << 4) - 0.0001;
		ray->x = (ptr->player->y - ray->y) * a_tan + ptr->player->x;
		ray->yoffset = -ptr->map->block_size;
		ray->xoffset = -ray->yoffset * a_tan;
	}
}

void	ft_set_if_angle_is_looking_down(t_rays *ray, t_game_essentials *ptr,
		float a_tan)
{
	if (ray->angle < PI)
	{
		ray->y = (((int)ptr->player->y >> 4) << 4) + ptr->map->block_size;
		ray->x = (ptr->player->y - ray->y) * a_tan + ptr->player->x;
		ray->yoffset = ptr->map->block_size;
		ray->xoffset = -ray->yoffset * a_tan;
	}
}

void	ft_cast_2d_horizontal_rays(t_game_essentials *ptr, t_rays *ray)
{
	float	a_tan;

	ray->distance_horizontal = 100000;
	ray->distance_x_horizontal = ptr->player->x;
	ray->distance_y_horizontal = ptr->player->y;
	ray->steps_to_obstacle = 0;
	a_tan = -1 / tan(ray->angle);
	ft_set_if_angle_is_looking_up(ray, ptr, a_tan);
	ft_set_if_angle_is_looking_down(ray, ptr, a_tan);
	if (ray->angle == 2 * PI || ray->angle == PI)
	{
		ray->x = ptr->player->x;
		ray->y = ptr->player->y;
	}
	ft_set_ray_x_y_horizontal(ray, ptr);
}
