/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 00:46:05 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 07:59:11 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->textures[i].img)
			mlx_destroy_image(data->mlx, data->textures[i].img);
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_all(t_data data)
{
	free_textures(&data);
	if (data.img)
		mlx_destroy_image(data.mlx, data.img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
