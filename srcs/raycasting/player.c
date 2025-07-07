/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:00:00 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/02 16:52:13 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player(t_data *data, double move_x, double move_y)
{
	double	new_x;
	double	new_y;

	new_x = data->ray.pos_x + move_x;
	new_y = data->ray.pos_y + move_y;
	if (data->map[(int)data->ray.pos_y][(int)new_x] != '1')
		data->ray.pos_x = new_x;
	if (data->map[(int)new_y][(int)data->ray.pos_x] != '1')
		data->ray.pos_y = new_y;
}

void	rotate_player(t_data *data, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dir_x;
	data->ray.dir_x = data->ray.dir_x * cos(angle) - data->ray.dir_y
		* sin(angle);
	data->ray.dir_y = old_dir_x * sin(angle) + data->ray.dir_y * cos(angle);
	old_plane_x = data->ray.plane_x;
	data->ray.plane_x = data->ray.plane_x * cos(angle) - data->ray.plane_y
		* sin(angle);
	data->ray.plane_y = old_plane_x * sin(angle) + data->ray.plane_y
		* cos(angle);
}

static void	handle_movement_keys(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_W)
		move_player(data, data->ray.dir_x * MOVE_SPEED, data->ray.dir_y
			* MOVE_SPEED);
	if (keycode == XK_s || keycode == XK_S)
		move_player(data, -data->ray.dir_x * MOVE_SPEED, -data->ray.dir_y
			* MOVE_SPEED);
	if (keycode == XK_a || keycode == XK_A)
		move_player(data, -data->ray.plane_x * MOVE_SPEED, -data->ray.plane_y
			* MOVE_SPEED);
	if (keycode == XK_d || keycode == XK_D)
		move_player(data, data->ray.plane_x * MOVE_SPEED, data->ray.plane_y
			* MOVE_SPEED);
}

static void	handle_rotation_keys(int keycode, t_data *data)
{
	if (keycode == XK_Right)
		rotate_player(data, ROT_SPEED);
	if (keycode == XK_Left)
		rotate_player(data, -ROT_SPEED);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		free_textures(data);
		free_map(data->tmp_map);
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->window);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
	}
	handle_movement_keys(keycode, data);
	handle_rotation_keys(keycode, data);
	render_frame(data);
	return (0);
}
