/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 20:01:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/19 16:03:02 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
    mlx_image_t	*img2;

	mlx = mlx_init(500, 500, "eae", true);
	if (!mlx)
		return (1);
	img = mlx_new_image(mlx, 500, 500);
    img2 = mlx_new_image(mlx, 500, 500);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, img2, 0, 0);
	img->instances[0].z = 1;
	img2->instances[0].z = -1;
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 250; j++) // Metade superior
		{
			mlx_put_pixel(img, i, j, 0xBBBBBBBB); // Branco
		}
		for (int j = 200; j < 500; j++) // Metade inferior
		{
			mlx_put_pixel(img2, i, j, 0x00FF0FFF); // Vermelho
		}
		for (int j = 0; j < 250; j++) // Metade superior
		{
			mlx_put_pixel(img, i, j, 0xBBBDDDB); // Branco
		}
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (0);
}
