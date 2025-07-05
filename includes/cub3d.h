/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 07:28:27 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 07:59:28 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_texture
{
	void		*img;
	char		*data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_texture;

typedef struct s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}				t_ray;

typedef struct s_data
{
	char		**map;
	char		**tmp_map;
	char		*texture_n;
	char		*texture_s;
	char		*texture_w;
	char		*texture_e;
	char		*floor_color;
	char		*sky_color;
	char		player_orientation;
	int			p_x;
	int			p_y;

	void		*mlx;
	void		*window;
	void		*img;
	char		*img_data;
	int			img_bpp;
	int			img_size_line;
	int			img_endian;

	t_texture	textures[4];
	t_ray		ray;
	int			floor_rgb;
	int			ceiling_rgb;
	int			map_width;
	int			map_height;
}				t_data;

/*parsing*/
int				map_ok(char *file_map, t_data *data);
int				check(t_data *data);
int				character_condition(t_data *data, int i, int j, int *count);
int				get_textures_colors(t_data *data, char **maps);

/*execution*/
int				init_window(t_data *data);
int				close_window_cross(t_data *data);

/*raycasting*/
int				init_raycasting(t_data *data);
int				load_textures(t_data *data);
void			render_frame(t_data *data);
void			cast_ray(t_data *data, int x);
void			calculate_ray(t_data *data, int x);
void			perform_dda(t_data *data);
void			calculate_wall_distance(t_data *data);
void			draw_wall_column(t_data *data, int x);

/*player*/
void			init_player(t_data *data);
int				handle_keypress(int keycode, t_data *data);
void			move_player(t_data *data, double move_x, double move_y);
void			rotate_player(t_data *data, double angle);

/*utils*/
int				is_space(char c);
int				height_map(char **tab);
int				rgb_to_int(char *rgb_str);
void			put_pixel(t_data *data, int x, int y, int color);
int				get_texture_pixel(t_texture *tex, int x, int y);

/*free*/
void			free_map(char **map);
void			destroy_all(t_data data);
void			free_textures(t_data *data);

/*debug*/
void			print_tab(char **tab);
void			print_data(t_data *data);

#endif