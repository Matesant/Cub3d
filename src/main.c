/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:23:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/19 16:49:46 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_background(mlx_image_t *img)
{
	uint32_t	*pixel;
	uint32_t	index;
	uint32_t	midle;

	pixel = (uint32_t *) img->pixels;
	index = img->height * img->width;
	midle = index / 2;
	while (index--)
	{
		if (index < midle)
			pixel[index] = 0xff000000;
		else
			pixel[index] = 0xff00ffff;
	}
}

void	single_color(mlx_image_t *img)
{
	uint32_t	*pixel;
	uint32_t	index;

	pixel = (uint32_t *) img->pixels;
	index = img->height * img->width;
	while (index--)
		pixel[index] = 0xff0000ff;
}
int	main(void)
{
	// t_game_essentials	ptr = {0};

	// ft_pre_verifications(&ptr, argc, argv);
	// ft_init_mlx(&ptr);
	// parse(&ptr, argv[1]);
	// ft_player_configs(&ptr);

	t_vector	player;
	t_vector	dir;
	t_vector	plane;
	t_vector	current_ray;

	player = (t_vector) {22, 12};
	dir = (t_vector) {-1, 0};
	player = (t_vector) {0, 0.66};
	double	time;
	double	old_time;

	while (1)
	{
		int x;

		x = -1;
		while (++x < WIDTH)
		{
			double camera_x = 2 * x / w - 1;
			current_ray.x = dir.x + plane.x * camera_x;
			current_ray.y = dir.y + plane.y * camera_x;

			int mapX = player.x;
			int mapY = player.y;
			double first_x_hit;
			double first_y_hit;

			double x_step
		}
	}
	mlx_loop_hook(ptr.mlx, ft_hook, &ptr);
	mlx_loop_hook(ptr.mlx, ft_key_hooks, &ptr);
	mlx_loop(ptr.mlx);
	
	return (0);
}

