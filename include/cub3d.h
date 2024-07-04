/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:10:01 by matesant          #+#    #+#             */
/*   Updated: 2024/07/04 15:58:43 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define HEIGHT 1024
# define WIDTH 512


typedef struct s_mlx_essentials
{
	void		*ptr;
	mlx_image_t	*img;
}				t_mlx_essentials;

t_bool	ft_pre_verifications(int argc, char **argv);
#endif