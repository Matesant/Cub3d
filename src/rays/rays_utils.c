/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:54 by matesant          #+#    #+#             */
/*   Updated: 2024/07/24 13:35:31 by matesant         ###   ########.fr       */
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

void draw_vertical_line(mlx_image_t *img, int x, int line_start, int line_end, uint32_t color)
{
    int y;

    for (y = line_start; y < line_end; y++)
    {
        if (y >= 0 && y < HEIGHT) // Garantir que não desenhe fora da tela
        {
            put_pixel(img, x, y, color);
        }
    }
}

void ft_draw_wall(t_game_essentials *ptr, t_rays *ray)
{
    int x;
    float final_distance;
    int line_height;
    int line_start;
    int line_end;
    uint32_t wall_color = 0xAAAAAAFF; // Cor da parede

    line_height = 0;
    x = -1;
    while (++x < WIDTH)
    {
        final_distance = ray->distances[x];
        line_height = (ptr->map->block_size * HEIGHT) / final_distance;
        if (line_height > HEIGHT)
            line_height = HEIGHT;
        line_start = (HEIGHT / 2) - (line_height / 2);
        line_end = (HEIGHT / 2) + (line_height / 2);

        if (ray->cardial[x] == 1)
        	draw_vertical_line(ptr->img, x, line_start, line_end, wall_color);
        else
        	draw_vertical_line(ptr->img, x, line_start, line_end, wall_color / 2);
    }
}


void	ft_cast_rays(t_game_essentials *ptr, t_rays *ray)
{
	float	angle_diff;

	while (ray->amount++ < WIDTH)
	{
		ray->angle = ft_normalize_angle(ray->angle);
		ft_cast_2d_horizontal_rays(ptr, ray);
		ft_cast_2d_vertical_rays(ptr, ray);
		if (ray->distance_horizontal < ray->distance_vertical)
		{
			ray->x = ray->distance_x_horizontal;
			ray->y = ray->distance_y_horizontal;
			ray->distances[ray->amount] = ray->distance_horizontal;
			ray->cardial[ray->amount] = 1;
		}
		else if (ray->distance_horizontal > ray->distance_vertical)
		{
			ray->x = ray->distance_x_vertical;
			ray->y = ray->distance_y_vertical;
			ray->distances[ray->amount] = ray->distance_vertical;
			ray->cardial[ray->amount] = 2;
		}
		//ft_put_line(ptr->img, ray->x, ray->y, ptr->player);
		angle_diff = cos(ptr->player->angle - ray->angle);
		ray->distances[ray->amount] = ray->distances[ray->amount] * angle_diff;
		ray->angle += STEP;
	}
}

void	ft_make_game(t_game_essentials *ptr)
{
	t_rays ray;

	ray = (t_rays) {0};
	ray.angle = ptr->player->angle - RAD * 30;
	ft_cast_rays(ptr, &ray);
	ft_draw_wall(ptr, &ray);
}
