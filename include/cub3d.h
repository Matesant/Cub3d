/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:10:01 by matesant          #+#    #+#             */
/*   Updated: 2024/07/12 01:24:34 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC MLX_KEY_ESCAPE
# define KEY_W MLX_KEY_W
# define KEY_A MLX_KEY_A
# define KEY_S MLX_KEY_S
# define KEY_D MLX_KEY_D
# define HEIGHT 1024
# define WIDTH 512

typedef struct s_map
{
	int					width;
	int					height;
	int					block_x;
	int					block_y;
	int					block_size;
	char				**map_matrice;
}						t_map;

typedef struct s_player_position
{
	float				x;
	float				y;
}						t_player_position;

typedef struct s_game_essentials
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	t_player_position	*player;
	t_map				*map;
	int					fd;
}						t_game_essentials;

t_bool					ft_pre_verifications(int argc, char **argv);
t_bool					ft_set_game_configs(char *map, t_game_essentials *game);
void					ft_color_background(t_game_essentials *ptr, int color);
void					ft_key_hooks(mlx_key_data_t key, void *param);
void					ft_hook(void *param);
void					ft_resize_hook(int width, int height, void *param);
void					ft_color_background(t_game_essentials *ptr, int color);
void					ft_put_player(mlx_image_t *img,
							t_player_position *player, t_map *map);
void					ft_draw_map(t_game_essentials *game, int block_size);
void					ft_update_map(t_game_essentials *game, int block_size);
int						ft_return_y(char character, t_map *map);
int						ft_return_x(char character, t_map *map);

#endif