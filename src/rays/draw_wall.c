/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 04:01:23 by matesant          #+#    #+#             */
/*   Updated: 2024/07/30 14:10:22 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgb(mlx_texture_t *texture, int x, int y)
{
	uint8_t	*rgb;

	rgb = &texture->pixels[(y * texture->width + x) * 4];
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}

void	ft_put_texture(mlx_image_t *img, t_wall wall, mlx_texture_t *texture,
		t_game_essentials *ptr)
{
	double	increase_factor;
	double	texture_y;
	int		y_minimum;
	int		y_maximum;

	if (texture == ptr->textures[SOUTH] || texture == ptr->textures[WEST])
		wall.x = (texture->width - 1) - wall.x;
	increase_factor = (texture->height / wall.height) * 0.5;
	y_minimum = (HEIGHT * 0.5) - wall.height;
	y_maximum = (HEIGHT * 0.5) + wall.height;
	texture_y = 0;
	while (y_minimum < y_maximum)
	{
		put_pixel(img, wall.y, y_minimum, get_rgb(texture, wall.x,
				(int)texture_y));
		texture_y += increase_factor;
		y_minimum++;
	}
}

void	ft_draw_wall(t_game_essentials *ptr, t_rays *ray, int x)
{
	t_wall			wall;
	mlx_texture_t	*texture;

	texture = NULL;
	wall.height = (ptr->map->block_size * (WIDTH * 0.5)) / ray->distance;
	wall.y = x;
	if (ray->axis == HORIZONTAL && ft_is_north(ray->angle))
		texture = ptr->textures[NORTH];
	else if (ray->axis == HORIZONTAL && ft_is_south(ray->angle))
		texture = ptr->textures[SOUTH];
	else if (ray->axis == VERTICAL && ft_is_east(ray->angle))
		texture = ptr->textures[EAST];
	else if (ray->axis == VERTICAL && ft_is_west(ray->angle))
		texture = ptr->textures[WEST];
	if (ray->axis == HORIZONTAL)
		wall.x = (int)(ray->x * ptr->map->block_size / 4) % texture->width;
	else
		wall.x = (int)(ray->y * ptr->map->block_size / 4) % texture->width;
	ft_put_texture(ptr->walls, wall, texture, ptr);
}
