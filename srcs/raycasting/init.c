/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:00:00 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 08:01:10 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_data *data)
{
	data->ray.pos_x = (double)data->p_x + 0.5;
	data->ray.pos_y = (double)data->p_y + 0.5;
	if (data->player_orientation == 'N')
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = -1;
		data->ray.plane_x = 0.66;
		data->ray.plane_y = 0;
	}
	else if (data->player_orientation == 'S')
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = 1;
		data->ray.plane_x = -0.66;
		data->ray.plane_y = 0;
	}
}

static void	init_player_orientation2(t_data *data)
{
	if (data->player_orientation == 'E')
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
		data->ray.plane_x = 0;
		data->ray.plane_y = 0.66;
	}
	else if (data->player_orientation == 'W')
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
		data->ray.plane_x = 0;
		data->ray.plane_y = -0.66;
	}
}

static void	init_map_dimensions(t_data *data)
{
	int	i;
	int	max_width;

	data->map_height = 0;
	while (data->map[data->map_height])
		data->map_height++;
	data->map_width = 0;
	i = 0;
	while (i < data->map_height)
	{
		max_width = ft_strlen(data->map[i]);
		if (max_width > data->map_width)
			data->map_width = max_width;
		i++;
	}
}

int	init_raycasting(t_data *data)
{
	init_player(data);
	init_player_orientation2(data);
	init_map_dimensions(data);
	data->floor_rgb = rgb_to_int(data->floor_color);
	data->ceiling_rgb = rgb_to_int(data->sky_color);
	if (!load_textures(data))
	{
		close_window_cross(data);
		return (0);
	}
	data->img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img)
	{
		close_window_cross(data);
		return (0);
	}
	data->img_data = mlx_get_data_addr(data->img, &data->img_bpp,
			&data->img_size_line, &data->img_endian);
	return (1);
}
