/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:10:01 by matesant          #+#    #+#             */
/*   Updated: 2024/08/01 16:41:09 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../../libs/MLX42/include/MLX42/MLX42.h"
# include "../../libs/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define CLEAR_STATIC -1
# define KEY_ESC MLX_KEY_ESCAPE
# define KEY_W MLX_KEY_W
# define KEY_A MLX_KEY_A
# define KEY_S MLX_KEY_S
# define KEY_D MLX_KEY_D
# define HEIGHT 720
# define HEIGHT2 360
# define WIDTH 1080
# define WIDTH2 540
# define MOVE_SPEED 3.0
# define FOV 0
# define PI 3.14159265359
# define P2 1.57079632679
# define P3 4.71238898038
# define EPSILON 1e-6
# define RAD 0.0174533
# define STEP 0.000969628

typedef enum e_orientation
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}					t_orientation;

typedef enum e_axis
{
	HORIZONTAL,
	VERTICAL
}					t_axis;

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_rays
{
	int				mapx;
	int				mapy;
	float			a_tan;
	float			x;
	float			y;
	float			angle;
	float			xoffset;
	float			yoffset;
	float			distance_horizontal;
	float			distance_vertical;
	float			distance_y_horizontal;
	float			distance_x_horizontal;
	float			distance_x_vertical;
	float			distance_y_vertical;
	float			distance;
	int				axis;
}					t_rays;

typedef struct s_map
{
	int				width;
	int				height;
	int				block_x;
	int				block_y;
	int				block_size;
	char			**raw_data;
	char			**map_matrice;
	char			*texture_path_no;
	char			*texture_path_so;
	char			*texture_path_we;
	char			*texture_path_ea;
	uint32_t		ceiling_color;
	uint32_t		floor_color;
	t_bool			textures_obtained;
	t_bool			colors_obtained;
}					t_map;

typedef struct s_player_position
{
	float			x;
	float			y;
	int				size;
	int				delta_x;
	int				delta_y;
	int				line_x;
	int				line_y;
	float			angle;
	t_vector		pos;
}					t_player_pos;

typedef struct s_line
{
	int				deltax;
	int				step_x;
	int				deltay;
	int				step_y;
	int				error_accumulated;
	int				double_error;
}					t_line;

typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	uint32_t		color;
}					t_point;

typedef struct s_wall
{
	float			height;
	float			x;
	float			y;
}					t_wall;

typedef struct s_line_drawing_data
{
	int				dx;
	int				dy;
	int				control;
	int				inc_x;
	int				inc_y;
}					t_line_drawing_data;

typedef struct s_game_essentials
{
	mlx_t			*mlx;
	mlx_image_t		*walls;
	mlx_image_t		*mini_map;
	mlx_texture_t	*textures[4];
	t_player_pos	*player;
	t_map			*map;
	int				fd;
}					t_game_essentials;

/*-----------------------PARSE------------------*/
void				validade_argv(t_game_essentials *game, int argc,
						char **argv);
void				get_textures(t_game_essentials *game, char **raw_data);
void				get_map_matrice(t_game_essentials *game, char **raw_data);
void				replace_tabs_for_spaces(char *raw_data[]);
void				get_matrice_dimensions(t_map *map);
int					get_matrice_lines_count(char **raw_data);
t_bool				is_map_matrice(char *line);
t_bool				check_invalid_chars(char **map_matrice);
t_bool				check_player_position(char **map_matrice);
void				load_textures(t_game_essentials *game);
void				get_colors(t_game_essentials *game, char **raw_data);
void				parse(t_game_essentials *game, char *map);
t_bool				is_wall(t_game_essentials *game, int key);
void				ft_init_player(t_game_essentials *game);
void				ft_init_mlx(t_game_essentials *game);
/*-----------------------------------------------*/

/*----------------------RENDER-------------------*/
void				ft_draw_map(t_game_essentials *game, int block_size);
void				ft_put_player(mlx_image_t *img, t_player_pos *player);
void				render_next_frame(void *param);
void				ft_draw_background(t_game_essentials *game,
						mlx_image_t *img, int width, int height);
void				new_line_data(t_line_drawing_data *line_data, t_point start,
						t_point end);
void				draw_line(mlx_image_t *img, t_point start, t_point end);
void				put_pixel(mlx_image_t *img, int x, int y, uint32_t color);
/*-----------------------------------------------*/

/*--------------------MOVEMENTS------------------*/
void				check_movement_keys(void *param);
void				toggle_minimap(mlx_key_data_t keydata, void *param);
t_bool				ft_is_north(float angle);
t_bool				ft_is_south(float angle);
t_bool				ft_is_west(float angle);
t_bool				ft_is_east(float angle);
void				ft_move_right(t_game_essentials *game);
void				ft_move_left(t_game_essentials *game);
void				ft_move_d(t_game_essentials *game);
void				ft_move_a(t_game_essentials *game);
void				ft_move_s(t_game_essentials *game);
void				ft_move_w(t_game_essentials *game);
void				mouse_hook(double x, double y, void *param);
/*-----------------------------------------------*/

/*----------------------RAYCAST------------------*/
void				ft_cast_2d_horizontal_rays(t_game_essentials *game,
						t_rays *ray);
void				ft_cast_2d_vertical_rays(t_game_essentials *game,
						t_rays *ray);
void				ft_ray_cast(t_game_essentials *game);
t_bool				fits_in_matrix(t_game_essentials *game, t_rays *ray);
void				ft_draw_wall(t_game_essentials *game, t_rays *ray, int x);
void				ft_draw_ray(t_game_essentials *game, t_rays *ray);
/*-----------------------------------------------*/

/*----------------------UTILS-------------------*/
void				error(t_game_essentials *game, char *error_msg);
void				clear(t_game_essentials *game);
void				close_hook(void *param);
/*----------------------------------------------*/

#endif
