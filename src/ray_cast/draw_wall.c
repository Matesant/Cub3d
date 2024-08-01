/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 04:01:23 by matesant          #+#    #+#             */
/*   Updated: 2024/07/30 15:01:08 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static uint32_t	get_rgb(mlx_texture_t *texture, int x, int y);
static void	ft_put_texture(mlx_image_t *img, t_wall wall, mlx_texture_t *texture,
		t_game_essentials *game);

void	ft_draw_wall(t_game_essentials *game, t_rays *ray, int x)
{
	t_wall			wall;
	mlx_texture_t	*texture;

	texture = NULL;
	wall.height = (game->map->block_size * (WIDTH * 0.5)) / ray->distance;
	wall.y = x;
	if (ray->axis == HORIZONTAL && ft_is_north(ray->angle))
		texture = game->textures[NORTH];
	else if (ray->axis == HORIZONTAL && ft_is_south(ray->angle))
		texture = game->textures[SOUTH];
	else if (ray->axis == VERTICAL && ft_is_east(ray->angle))
		texture = game->textures[EAST];
	else if (ray->axis == VERTICAL && ft_is_west(ray->angle))
		texture = game->textures[WEST];
	if (ray->axis == HORIZONTAL)
		wall.x = (int)(ray->x * game->map->block_size / 4) % texture->width;
	else
		wall.x = (int)(ray->y * game->map->block_size / 4) % texture->width;
	ft_put_texture(game->walls, wall, texture, game);
}

static uint32_t	get_rgb(mlx_texture_t *texture, int x, int y)
{
	uint8_t	*rgb;

	rgb = &texture->pixels[(y * texture->width + x) * 4];
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}

static void	ft_put_texture(mlx_image_t *img, t_wall wall, mlx_texture_t *texture,
		t_game_essentials *game)
{
	double	increase_factor;
	double	texture_y;
	int		y_minimum;
	int		y_maximum;

	if (texture == game->textures[SOUTH] || texture == game->textures[WEST])
		wall.x = (texture->width - 1) - wall.x;
	if (wall.height > HEIGHT * 4)
	{
		wall.height = HEIGHT * 10;
	}
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


