/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rays_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:30:55 by matesant          #+#    #+#             */
/*   Updated: 2024/08/01 16:18:29 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_set_ray_x_y_vertical(t_rays *ray, t_game_essentials *game);
static void	ft_set_if_angle_is_looking_right(t_rays *ray,
				t_game_essentials *game, float n_tan);
static void	ft_set_if_angle_is_looking_left(t_rays *ray,
				t_game_essentials *game, float n_tan);

void	ft_cast_2d_vertical_rays(t_game_essentials *game, t_rays *ray)
{
	float	n_tan;

	ray->distance_vertical = 100000;
	ray->distance_x_vertical = game->player->x;
	ray->distance_y_vertical = game->player->y;
	n_tan = -tan(ray->angle);
	ft_set_if_angle_is_looking_left(ray, game, n_tan);
	ft_set_if_angle_is_looking_right(ray, game, n_tan);
	if (ft_fabs(ray->angle) < EPSILON || ft_fabs(ray->angle - PI) < EPSILON)
	{
		ray->x = game->player->x;
		ray->y = game->player->y;
	}
	ft_set_ray_x_y_vertical(ray, game);
}

static void	ft_set_if_angle_is_looking_left(t_rays *ray,
		t_game_essentials *game, float n_tan)
{
	if (ray->angle > P2 && ray->angle < P3)
	{
		ray->x = (((int)game->player->x / game->map->block_size)
				* game->map->block_size) - 0.0001;
		ray->y = (game->player->x - ray->x) * n_tan + game->player->y;
		ray->xoffset = -game->map->block_size;
		ray->yoffset = -ray->xoffset * n_tan;
	}
}

static void	ft_set_if_angle_is_looking_right(t_rays *ray,
		t_game_essentials *game, float n_tan)
{
	if (ray->angle < P2 || ray->angle > P3)
	{
		ray->x = (((int)game->player->x / game->map->block_size)
				* game->map->block_size) + game->map->block_size;
		ray->y = (game->player->x - ray->x) * n_tan + game->player->y;
		ray->xoffset = game->map->block_size;
		ray->yoffset = -ray->xoffset * n_tan;
	}
}

static void	ft_set_ray_x_y_vertical(t_rays *ray, t_game_essentials *game)
{
	while (1)
	{
		ray->mapx = (int)(ray->x) / game->map->block_size;
		ray->mapy = (int)(ray->y) / game->map->block_size;
		if (fits_in_matrix(game, ray))
		{
			if (game->map->map_matrice[ray->mapy][ray->mapx] == '1')
			{
				ray->distance_x_vertical = ray->x;
				ray->distance_y_vertical = ray->y;
				ray->distance_vertical = hypot(game->player->x - ray->x,
						game->player->y - ray->y);
				return ;
			}
			else
			{
				ray->x += ray->xoffset;
				ray->y += ray->yoffset;
			}
		}
		else
			break ;
	}
}
