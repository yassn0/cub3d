/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 01:05:44 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/02 15:37:47 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (0);
	data->window = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"cub3d");
	if (data->window == NULL)
	{
		free(data->window);
		return (0);
	}
	return (1);
}

int	close_window_cross(t_data *data)
{
	if (data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
		data->window = NULL;
	}
	destroy_all(*data);
	free_map(data->tmp_map);
	exit(0);
	return (0);
}
