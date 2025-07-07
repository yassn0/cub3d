/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:00:00 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 07:47:33 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_texture_mapping(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.wall_x = data->ray.pos_y + data->ray.perp_wall_dist
			* data->ray.ray_dir_y;
	else
		data->ray.wall_x = data->ray.pos_x + data->ray.perp_wall_dist
			* data->ray.ray_dir_x;
	data->ray.wall_x -= floor(data->ray.wall_x);
	data->ray.tex_x = (int)(data->ray.wall_x
			* (double)data->textures[data->ray.tex_num].width);
	if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
		data->ray.tex_x = data->textures[data->ray.tex_num].width
			- data->ray.tex_x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		data->ray.tex_x = data->textures[data->ray.tex_num].width
			- data->ray.tex_x - 1;
	data->ray.step = 1.0 * data->textures[data->ray.tex_num].height
		/ data->ray.line_height;
	data->ray.tex_pos = (data->ray.draw_start - WINDOW_HEIGHT / 2
			+ data->ray.line_height / 2) * data->ray.step;
}

static void	determine_texture_num(t_data *data)
{
	if (data->ray.side == 0)
	{
		if (data->ray.ray_dir_x > 0)
			data->ray.tex_num = 3;
		else
			data->ray.tex_num = 2;
	}
	else
	{
		if (data->ray.ray_dir_y > 0)
			data->ray.tex_num = 1;
		else
			data->ray.tex_num = 0;
	}
}

void	draw_wall_column(t_data *data, int x)
{
	int	y;
	int	tex_y;
	int	color;

	determine_texture_num(data);
	calculate_texture_mapping(data);
	y = data->ray.draw_start;
	while (y < data->ray.draw_end)
	{
		tex_y = (int)data->ray.tex_pos
			& (data->textures[data->ray.tex_num].height - 1);
		data->ray.tex_pos += data->ray.step;
		color = get_texture_pixel(&data->textures[data->ray.tex_num],
				data->ray.tex_x, tex_y);
		if (data->ray.side == 1)
			color = (color >> 1) & 8355711;
		put_pixel(data, x, y, color);
		y++;
	}
}

static void	draw_floor_ceiling(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->ray.draw_start)
	{
		put_pixel(data, x, y, data->ceiling_rgb);
		y++;
	}
	y = data->ray.draw_end;
	while (y < WINDOW_HEIGHT)
	{
		put_pixel(data, x, y, data->floor_rgb);
		y++;
	}
}

void	render_frame(t_data *data)
{
	int	x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		cast_ray(data, x);
		draw_floor_ceiling(data, x);
		draw_wall_column(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
