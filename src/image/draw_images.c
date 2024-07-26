/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:39:08 by matesant          #+#    #+#             */
/*   Updated: 2024/07/26 06:40:22 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_ray(t_game_essentials *game, t_rays *ray)
{
	t_point	start;
	t_point	end;

	start.x = game->player->x;
	start.y = game->player->y;
	end.x = ray->x;
	end.y = ray->y;
	draw_line(game->img_map, start, end);
}

void	ft_draw_background(t_game_essentials *game, mlx_image_t *img, int width,
		int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height / 2)
		{
			mlx_put_pixel(img, x, y, game->map->ceiling_color);
			y++;
		}
		x++;
	}
	x = 0;
	while (x < width)
	{
		y = height / 2;
		while (y < height)
		{
			mlx_put_pixel(img, x, y, game->map->floor_color);
			y++;
		}
		x++;
	}
}

void	ft_put_player(mlx_image_t *img, t_player_pos *player)
{
	t_point	start;
	t_point	end;
	int		line_length;

	start.color = 0xff0000ff;
	start.x = player->x - (player->size / 2);
	while (start.x < player->x + (player->size / 2))
	{
		start.y = player->y - (player->size / 2);
		while (start.y < player->y + (player->size / 2))
		{
			end.x = player->x + (player->size / 2) - 1;
			end.y = player->y + (player->size / 2) - 1;
			draw_line(img, start, end);
			start.y++;
		}
		start.x++;
	}
	start.x = player->x;
	start.y = player->y;
	start.color = 0x00FFFFFF;
	line_length = 15;
	end.x = player->x + line_length * cos(player->angle);
	end.y = player->y + line_length * sin(player->angle);
	draw_line(img, start, end);
}

void	ft_put_rectangle(t_game_essentials *game, int x, int y, int color)
{
	t_point	start;
	t_point	end;
	int		yo;

	yo = 0;
	while (yo < game->map->block_size)
	{
		start.x = x;
		start.y = y + yo;
		start.color = color;
		end.x = x + game->map->block_size;
		end.y = y + yo;
		end.color = color;
		draw_line(game->img_map, start, end);
		yo++;
	}
}

void	ft_draw_map(t_game_essentials *game, int block_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			game->map->block_x = (j * block_size);
			game->map->block_y = (i * block_size);
			if (game->map->map_matrice[i][j] == '1')
				ft_put_rectangle(game, game->map->block_x, game->map->block_y,
					0x00FF00FF);
			else
				ft_put_rectangle(game, game->map->block_x, game->map->block_y,
					0x000000FF);
			j++;
		}
		i++;
	}
}
