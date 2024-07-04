/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:23:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/04 16:11:13 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color_background(mlx_t *mlx, int color, mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->width)
	{
		y = 0;
		while (y < mlx->height)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}

static void	ft_hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char *argv[])
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (ft_pre_verifications(argc, argv))
		return (1);
	mlx = mlx_init(HEIGHT, WIDTH, "eae", true);
	img = mlx_new_image(mlx, HEIGHT, WIDTH);
	mlx_image_to_window(mlx, img, 0, 0);
	ft_color_background(mlx, 0xFF0000FF, img);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
