/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:54 by matesant          #+#    #+#             */
/*   Updated: 2024/07/25 14:46:00 by matesant         ###   ########.fr       */
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

void ft_draw_wall(t_game_essentials *ptr, t_rays *ray)
{
    int x;
    float final_distance;
    int line_height;
    int line_start;
    int line_end;
	t_point start;
	t_point end;

	start.color = 0xbbbbbbbb;
	x = 0;
    while (x < WIDTH)
    {
		start.x = x;
        final_distance = ray->distances[x];
        line_height = (ptr->map->block_size * HEIGHT) / final_distance;
        if (line_height > HEIGHT)
            line_height = HEIGHT;
        line_start = (HEIGHT / 2) - (line_height / 2);
		start.y = line_start;
		end.x = x;
        line_end = (HEIGHT / 2) + (line_height / 2);
		end.y = line_end;
		draw_line(ptr->img, start, end);
		x++;
    }
}


void	ft_cast_rays(t_game_essentials *ptr, t_rays *ray)
{
	float	angle_diff;

	ray->angle = ptr->player->angle - RAD * 30;
	while (ray->amount < WIDTH)
	{
		ray->angle = ft_normalize_angle(ray->angle);
		ft_cast_2d_horizontal_rays(ptr, ray);
		ft_cast_2d_vertical_rays(ptr, ray);
		if (ray->distance_horizontal < ray->distance_vertical)
		{
			ray->x = ray->distance_x_horizontal;
			ray->y = ray->distance_y_horizontal;
			ray->distances[ray->amount] = ray->distance_horizontal;
		}
		else if (ray->distance_horizontal > ray->distance_vertical)
		{
			ray->x = ray->distance_x_vertical;
			ray->y = ray->distance_y_vertical;
			ray->distances[ray->amount] = ray->distance_vertical;
		}
		//ft_put_line(ptr->img, ray->x, ray->y, ptr->player);
		angle_diff = cos(ptr->player->angle - ray->angle);
		ray->distances[ray->amount] = ray->distances[ray->amount] * angle_diff;
		ray->angle += STEP;
		ray->amount++;
	}
}

void	ft_make_game(t_game_essentials *ptr)
{
	t_rays *ray;

	ray = malloc(sizeof(t_rays));
	ft_initiate_rays(ray);
	ft_cast_rays(ptr, ray);
	ft_draw_wall(ptr, ray);
	free(ray);
}