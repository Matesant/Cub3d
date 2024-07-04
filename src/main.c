/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 20:23:25 by matesant          #+#    #+#             */
/*   Updated: 2024/07/04 17:47:27 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_player(mlx_image_t *img, t_player_position *player)
{
	int x;
	int y;
	int player_size = 5;

	x = player->x - player_size;
	while (x <= player->x + player_size)
	{
		y = player->y - player_size;
		while (y <= player->y + player_size)
		{
			mlx_put_pixel(img, x, y, 0x00FF0000);
			y++;
		}
		x++;
	}
}


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

void ft_key_hooks(mlx_key_data_t key, void *param)
{
	t_mlx_essentials	*ptr;

	ptr = (t_mlx_essentials *)param;
	if (key.key == KEY_ESC)
		mlx_terminate(ptr->mlx);
	if (key.key == KEY_W)
		ptr->player->y -= 5;
	if (key.key == KEY_S)
		ptr->player->y += 5;
	if (key.key == KEY_A)
		ptr->player->x -= 5;
	if (key.key== KEY_D)
		ptr->player->x += 5;
}

static void	ft_hook(void *param)
{
	t_mlx_essentials	*ptr;

	ptr = (t_mlx_essentials *)param;
	ft_color_background(ptr->mlx, 0xFF0000FF, ptr->img);
	ft_put_player(ptr->img, ptr->player);
	printf("WIDTH: %d | HEIGHT: %d\n", ptr->mlx->width, ptr->mlx->height);
}

int	main(int argc, char *argv[])
{
	t_mlx_essentials	ptr = {0};

	ptr.mlx = NULL;
	if (ft_pre_verifications(argc, argv))
		return (1);
	ptr.mlx = mlx_init(HEIGHT, WIDTH, "eae", true);
	ptr.img = mlx_new_image(ptr.mlx, HEIGHT, WIDTH);
	mlx_image_to_window(ptr.mlx, ptr.img, 0, 0);
	ptr.player = malloc(sizeof(t_player_position));
	ptr.player->x = 400;
	ptr.player->y = 300;
	mlx_loop_hook(ptr.mlx, ft_hook, &ptr);
	mlx_key_hook(ptr.mlx, ft_key_hooks, &ptr);
	mlx_loop(ptr.mlx);
	mlx_terminate(ptr.mlx);
	return (0);
}
