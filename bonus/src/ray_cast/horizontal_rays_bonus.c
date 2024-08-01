/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:11:36 by matesant          #+#    #+#             */
/*   Updated: 2024/08/01 16:18:24 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_set_if_angle_is_looking_up(t_rays *ray, t_game_essentials *game,
				float a_tan);
static void	ft_set_if_angle_is_looking_down(t_rays *ray,
				t_game_essentials *game, float a_tan);
static void	ft_set_ray_x_y_horizontal(t_rays *ray, t_game_essentials *game);

void	ft_cast_2d_horizontal_rays(t_game_essentials *game, t_rays *ray)
{
	float	a_tan;

	ray->distance_horizontal = 100000;
	ray->distance_x_horizontal = game->player->x;
	ray->distance_y_horizontal = game->player->y;
	a_tan = -1 / tan(ray->angle);
	ft_set_if_angle_is_looking_up(ray, game, a_tan);
	ft_set_if_angle_is_looking_down(ray, game, a_tan);
	if (ray->angle == 2 * PI || ray->angle == PI)
	{
		ray->x = game->player->x;
		ray->y = game->player->y;
	}
	ft_set_ray_x_y_horizontal(ray, game);
}

static void	ft_set_if_angle_is_looking_up(t_rays *ray, t_game_essentials *game,
		float a_tan)
{
	if (ray->angle > PI)
	{
		ray->y = (((int)game->player->y >> 4) << 4) - 0.0001;
		ray->x = (game->player->y - ray->y) * a_tan + game->player->x;
		ray->yoffset = -game->map->block_size;
		ray->xoffset = -ray->yoffset * a_tan;
	}
}

static void	ft_set_if_angle_is_looking_down(t_rays *ray,
		t_game_essentials *game, float a_tan)
{
	if (ray->angle < PI)
	{
		ray->y = (((int)game->player->y >> 4) << 4) + game->map->block_size;
		ray->x = (game->player->y - ray->y) * a_tan + game->player->x;
		ray->yoffset = game->map->block_size;
		ray->xoffset = -ray->yoffset * a_tan;
	}
}

static void	ft_set_ray_x_y_horizontal(t_rays *ray, t_game_essentials *game)
{
	while (1)
	{
		if (fits_in_matrix(game, ray))
		{
			if (game->map->map_matrice[ray->mapy][ray->mapx] == '1')
			{
				ray->distance_x_horizontal = ray->x;
				ray->distance_y_horizontal = ray->y;
				ray->distance_horizontal = hypot(game->player->x - ray->x,
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
