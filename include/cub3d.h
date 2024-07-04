/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:10:01 by matesant          #+#    #+#             */
/*   Updated: 2024/07/04 17:36:23 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define KEY_ESC MLX_KEY_ESCAPE
# define KEY_W MLX_KEY_W
# define KEY_A MLX_KEY_A
# define KEY_S MLX_KEY_S
# define KEY_D MLX_KEY_D
# define HEIGHT 1024
# define WIDTH 512

typedef struct s_player_position
{
	float	x;
	float	y;
}				t_player_position;

typedef struct s_mlx_essentials
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_player_position	*player;
}				t_mlx_essentials;

t_bool	ft_pre_verifications(int argc, char **argv);
#endif