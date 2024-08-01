/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:31:54 by matesant          #+#    #+#             */
/*   Updated: 2024/08/01 15:07:10 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	ft_normalize_angle(float angle);
static void		ft_get_ray_distance(t_game_essentials *game, t_rays *rays);

void	ft_ray_cast(t_game_essentials *game)
{
	int		x;
	float	angle;
	t_rays	rays;

	ft_bzero(&rays, sizeof(t_rays));
	x = 0;
	angle = game->player->angle - RAD * 30;
	while (x < WIDTH)
	{
		rays.angle = angle;
		ft_get_ray_distance(game, &rays);
		ft_draw_wall(game, &rays, x);
		angle += STEP;
		x++;
	}
}

t_bool	fits_in_matrix(t_game_essentials *game, t_rays *ray)
{
	int	len;

	ray->mapx = (int)((ray->x) / game->map->block_size);
	ray->mapy = (int)((ray->y) / game->map->block_size);
	if (ray->mapy >= 0 && ray->mapy < game->map->height)
		len = ft_strlen(game->map->map_matrice[ray->mapy]);
	if (ray->mapy >= 0 && ray->mapy < game->map->height && ray->mapx >= 0
		&& ray->mapx < len)
		return (TRUE);
	return (FALSE);
}

static float	ft_normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * PI;
	while (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

static void	ft_get_ray_distance(t_game_essentials *game, t_rays *rays)
{
	float	angle_diff;

	rays->angle = ft_normalize_angle(rays->angle);
	ft_cast_2d_horizontal_rays(game, rays);
	ft_cast_2d_vertical_rays(game, rays);
	if (rays->distance_horizontal < rays->distance_vertical)
	{
		rays->x = rays->distance_x_horizontal;
		rays->y = rays->distance_y_horizontal;
		rays->distance = rays->distance_horizontal;
		rays->axis = HORIZONTAL;
	}
	else
	{
		rays->x = rays->distance_x_vertical;
		rays->y = rays->distance_y_vertical;
		rays->distance = rays->distance_vertical;
		rays->axis = VERTICAL;
	}
	ft_draw_ray(game, rays);
	angle_diff = cos(game->player->angle - rays->angle);
	rays->distance *= angle_diff;
}
