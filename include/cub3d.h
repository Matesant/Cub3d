/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:10:01 by matesant          #+#    #+#             */
/*   Updated: 2024/07/30 14:23:43 by matesant         ###   ########.fr       */
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

# define CLEAR_STATIC -1
# define KEY_ESC MLX_KEY_ESCAPE
# define KEY_W MLX_KEY_W
# define KEY_A MLX_KEY_A
# define KEY_S MLX_KEY_S
# define KEY_D MLX_KEY_D
# define HEIGHT 720
# define WIDTH 1080
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

void				ft_pre_verifications(t_game_essentials *game, int argc,
						char **argv);
t_bool				ft_set_game_configs(char *map, t_game_essentials *game);
void				ft_color_background(t_game_essentials *ptr, int color);
void				ft_key_hooks(void *param);
void				ft_hook(void *param);
void				ft_resize_hook(int width, int height, void *param);
void				ft_color_background(t_game_essentials *ptr, int color);
void				ft_put_player(mlx_image_t *img, t_player_pos *player);
void				ft_draw_map(t_game_essentials *game, int block_size);
void				ft_update_map(t_game_essentials *game, int block_size);
int					ft_return_y(char character, t_map *map);
int					ft_return_x(char character, t_map *map);
void				ft_init_mlx(t_game_essentials *ptr);
void				ft_player_configs(t_game_essentials *ptr);
void				ft_draw_background(t_game_essentials *game,
						mlx_image_t *img, int width, int height);
void				ft_put_line(mlx_image_t *img, int endx, int endy,
						t_player_pos *player);
void				ft_initiate_rays(t_rays *rays);
float				ft_normalize_angle(float angle);
void				ft_cast_2d_horizontal_rays(t_game_essentials *ptr,
						t_rays *ray);
void				ft_cast_2d_vertical_rays(t_game_essentials *ptr,
						t_rays *ray);
void				ft_set_ray_x_y_vertical(t_rays *ray,
						t_game_essentials *ptr);
void				ft_set_ray_x_y_horizontal(t_rays *ray,
						t_game_essentials *ptr);
float				calculate_distance_to_wall(float player_x, float player_y,
						float wall_x, float wall_y);
void				ft_make_game(t_game_essentials *ptr);
void				parse(t_game_essentials *game, char *map);
void				get_textures(t_game_essentials *game, char **raw_data);
void				error(t_game_essentials *game, char *error_msg);
void				get_colors(t_game_essentials *game, char **raw_data);
void				get_map_matrice(t_game_essentials *game, char **raw_data);
void				clear(t_game_essentials *game);
void				draw_line(mlx_image_t *img, t_point start, t_point end);
void				put_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void				new_line_data(t_line_drawing_data *line_data, t_point start,
						t_point end);
t_bool				is_wall(t_game_essentials *game, int key);
void				toggle_minimap(mlx_key_data_t keydata, void *param);
void				load_textures(t_game_essentials *game);
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
void				ft_draw_wall(t_game_essentials *ptr, t_rays *ray, int x);
void				ft_put_texture(mlx_image_t *img, t_wall wall,
						mlx_texture_t *texture, t_game_essentials *ptr);
void				ft_draw_ray(t_game_essentials *game, t_rays *ray);
void				ft_init_cordinates(t_line *cordinates, int endx, int endy,
						t_player_pos *player);
int					ft_return_y(char character, t_map *map);
int					ft_return_x(char character, t_map *map);
void				close_hook(void *param);

#endif
