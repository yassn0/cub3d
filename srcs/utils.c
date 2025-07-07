/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:30:22 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 08:43:12 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	height_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	character_condition(t_data *data, int i, int j, int *count)
{
	if (data->map[i][j] != '0' && data->map[i][j] != '1'
		&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
		&& data->map[i][j] != 'E' && data->map[i][j] != 'W'
		&& data->map[i][j] != ' ')
		return (0);
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
	{
		data->player_orientation = data->map[i][j];
		data->p_x = j;
		data->p_y = i;
		(*count)++;
	}
	return (1);
}

int	len_max_row(t_data *data)
{
	int	i;
	int	j;
	int	len_max;

	len_max = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
			j++;
		if (j > len_max)
			len_max = j;
		i++;
	}
	return (len_max);
}

int	rgb_to_int(char *rgb_str)
{
	char	**rgb_parts;
	int		r;
	int		g;
	int		b;
	int		color;

	rgb_parts = ft_split(rgb_str, ',');
	if (!rgb_parts)
		return (0);
	r = ft_atoi(rgb_parts[0]);
	g = ft_atoi(rgb_parts[1]);
	b = ft_atoi(rgb_parts[2]);
	color = (r << 16) | (g << 8) | b;
	free_map(rgb_parts);
	return (color);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	pixel = data->img_data + (y * data->img_size_line + x * (data->img_bpp
				/ 8));
	*(unsigned int *)pixel = color;
}
