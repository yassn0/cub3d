/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:00:00 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/02 16:00:04 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray(t_data *data, int x)
{
	data->ray.camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	data->ray.ray_dir_x = data->ray.dir_x + data->ray.plane_x
		* data->ray.camera_x;
	data->ray.ray_dir_y = data->ray.dir_y + data->ray.plane_y
		* data->ray.camera_x;
	data->ray.map_x = (int)data->ray.pos_x;
	data->ray.map_y = (int)data->ray.pos_y;
	if (data->ray.ray_dir_x == 0)
		data->ray.delta_dist_x = 1e30;
	else
		data->ray.delta_dist_x = fabs(1 / data->ray.ray_dir_x);
	if (data->ray.ray_dir_y == 0)
		data->ray.delta_dist_y = 1e30;
	else
		data->ray.delta_dist_y = fabs(1 / data->ray.ray_dir_y);
	data->ray.hit = 0;
}

static void	calculate_step_and_side_dist(t_data *data)
{
	if (data->ray.ray_dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->ray.pos_x - data->ray.map_x)
			* data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->ray.pos_x)
			* data->ray.delta_dist_x;
	}
	if (data->ray.ray_dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->ray.pos_y - data->ray.map_y)
			* data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->ray.pos_y)
			* data->ray.delta_dist_y;
	}
}

void	perform_dda(t_data *data)
{
	calculate_step_and_side_dist(data);
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map[data->ray.map_y][data->ray.map_x] == '1')
			data->ray.hit = 1;
	}
}

void	calculate_wall_distance(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perp_wall_dist = (data->ray.map_x - data->ray.pos_x + (1
					- data->ray.step_x) / 2) / data->ray.ray_dir_x;
	else
		data->ray.perp_wall_dist = (data->ray.map_y - data->ray.pos_y + (1
					- data->ray.step_y) / 2) / data->ray.ray_dir_y;
	data->ray.line_height = (int)(WINDOW_HEIGHT / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + WINDOW_HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + WINDOW_HEIGHT / 2;
	if (data->ray.draw_end >= WINDOW_HEIGHT)
		data->ray.draw_end = WINDOW_HEIGHT - 1;
}

void	cast_ray(t_data *data, int x)
{
	calculate_ray(data, x);
	perform_dda(data);
	calculate_wall_distance(data);
}
