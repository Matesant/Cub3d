/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:54 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 00:29:43 by matesant         ###   ########.fr       */
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

static uint32_t get_rgb(mlx_texture_t *texture, int x, int y)
{
	uint8_t *rgb;

	rgb = &texture->pixels[(y * texture->width + x) * 4];
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}

void ft_put_texture(mlx_image_t *img, t_wall wall, mlx_texture_t *texture, t_game_essentials *ptr)
{
	double increase_factor;
	double texture_y;
	double texture_offset;
	int y_minimum;
	int y_maximum;

	if (texture == ptr->textures[NORTH] || texture == ptr->textures[WEST])
		wall.x = (texture->width - 1) - wall.x;
	increase_factor = (texture->height / wall.height) * 0.5;
	texture_offset = 0;
	if (wall.height > HEIGHT)
	{
		texture_offset = wall.height - (HEIGHT * 0.5);
		wall.height = HEIGHT;
	}
	y_minimum = (HEIGHT / 2) - wall.height;
	y_maximum = (HEIGHT / 2) + wall.height;
	texture_y = texture_offset * increase_factor;
	while (y_minimum < y_maximum)
	{
		put_pixel(img, wall.y, y_minimum, get_rgb(texture, wall.x, (int)texture_y));
		texture_y += increase_factor;
		y_minimum++;
	}
}

void	ft_draw_wall(t_game_essentials *ptr, t_rays *ray, int x)
{
	t_wall			wall;
	int				line_height;
	mlx_texture_t	*texture;

	wall.height = (ptr->map->block_size * (WIDTH * 0.5)) / ray->distance;
	wall.y = x;
	if (wall.height > HEIGHT)
		wall.height = HEIGHT;
	if (ray->axis == HORIZONTAL && ft_is_north(ray->angle))
		texture = ptr->textures[NORTH];
	else if (ray->axis == HORIZONTAL && ft_is_south(ray->angle))
		texture = ptr->textures[SOUTH];
	else if (ray->axis == VERTICAL && ft_is_east(ray->angle))
		texture = ptr->textures[EAST];
	else if (ray->axis == VERTICAL && ft_is_west(ray->angle))
		texture = ptr->textures[WEST];
	else
		texture = ptr->textures[NORTH];
	if (ray->axis == HORIZONTAL)
		wall.x = (int)(ray->x * ptr->map->block_size / 4) % texture->width;
	else
		wall.x = (int)(ray->y * ptr->map->block_size / 4) % texture->width;
	ft_put_texture(ptr->img, wall, texture, ptr);
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
