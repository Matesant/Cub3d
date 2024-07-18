/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:11:36 by matesant          #+#    #+#             */
/*   Updated: 2024/07/18 00:43:40 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	ft_set_if_angle_is_looking_up(t_rays *ray, t_game_essentials *ptr)
{
	if (ray->angle > PI)
	{
		ray->y = (((int)ptr->player->y / ptr->map->block_size)
				* ptr->map->block_size) - 0.0001;
		ray->x = (ptr->player->y - ray->y) * ray->a_tan + ptr->player->x;
		ray->yoffset = -ptr->map->block_size;
		ray->xoffset = -ray->yoffset * ray->a_tan;
	}
}

void	ft_set_if_angle_is_looking_down(t_rays *ray, t_game_essentials *ptr)
{
	if (ray->angle < PI)
	{
		ray->y = (((int)ptr->player->y / ptr->map->block_size)
				* ptr->map->block_size) + ptr->map->block_size;
		ray->x = (ptr->player->y - ray->y) * ray->a_tan + ptr->player->x;
		ray->yoffset = ptr->map->block_size;
		ray->xoffset = -ray->yoffset * ray->a_tan;
	}
}

void	ft_set_ray_x_y(t_rays *ray, t_game_essentials *ptr)
{
	while (ray->steps_to_obstacle < 8)
	{
		ray->mapx = (int)(ray->x) / ptr->map->block_size;
		ray->mapy = (int)(ray->y) / ptr->map->block_size;
		if (ray->mapy >= 0 && ray->mapy < ptr->map->height && ray->mapx >= 0
			&& ray->mapx < ptr->map->width)
		{
			if (ptr->map->map_matrice[ray->mapy][ray->mapx] == '1')
				return ;
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

float	ft_fabs(float x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	ft_cast_2d_horizontal_rays(t_game_essentials *ptr)
{
	t_rays	*ray;

	ray = malloc(sizeof(t_rays));
	ft_initiate_rays(ray);
	ray->angle = ptr->player->angle;
	ray->angle = ft_normalize_angle(ray->angle);
	while (ray->amount++ < NUM_RAYS)
	{
		ray->steps_to_obstacle = 0;
		ray->a_tan = -1 / tan(ray->angle);
		ft_set_if_angle_is_looking_up(ray, ptr);
		ft_set_if_angle_is_looking_down(ray, ptr);
		if (ft_fabs(ray->angle) < EPSILON || ft_fabs(ray->angle - PI) < EPSILON)
		{
			ray->x = ptr->player->x;
			ray->y = ptr->player->y;
			ray->steps_to_obstacle = 8;
		}
		ft_set_ray_x_y(ray, ptr);
		ft_put_line(ptr->img, ray->x, ray->y, ptr->player);
	}
	free(ray);
}
