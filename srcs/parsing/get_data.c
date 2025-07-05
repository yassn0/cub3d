/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:49:31 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 07:49:14 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	process_texture(char *line, int j, char **texture_ptr)
{
	while (line[j] && is_space(line[j]))
		j++;
	if (line[j] && line[j] != '\n' && line[j] != '\0')
		*texture_ptr = &line[j];
	else
		*texture_ptr = NULL;
}

static void	handle_element(t_data *data, char *line, int j)
{
	if (!ft_strncmp(&line[j], "NO ", 3))
		process_texture(line, j + 3, &data->texture_n);
	else if (!ft_strncmp(&line[j], "SO ", 3))
		process_texture(line, j + 3, &data->texture_s);
	else if (!ft_strncmp(&line[j], "WE ", 3))
		process_texture(line, j + 3, &data->texture_w);
	else if (!ft_strncmp(&line[j], "EA ", 3))
		process_texture(line, j + 3, &data->texture_e);
	else if (!ft_strncmp(&line[j], "F ", 2))
		process_texture(line, j + 2, &data->floor_color);
	else if (!ft_strncmp(&line[j], "C ", 2))
		process_texture(line, j + 2, &data->sky_color);
}

static int	check_color(char *color)
{
	int		i;
	int		count;
	char	**rgb;

	if (!color)
		return (0);
	i = 0;
	count = 0;
	while (color[i])
	{
		if (color[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	rgb = ft_split(color, ',');
	if (!rgb)
		return (0);
	if (!rgb[0] || (ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255))
		return (free_map(rgb), 0);
	if (!rgb[1] || (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255))
		return (free_map(rgb), 0);
	if (!rgb[2] || (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
		return (free_map(rgb), 0);
	free_map(rgb);
	return (1);
}

static int	check_element(t_data *data)
{
	if (!check_color(data->floor_color))
		return (0);
	if (!check_color(data->sky_color))
		return (0);
	if (!data->texture_n)
		return (0);
	if (!data->texture_e)
		return (0);
	if (!data->texture_w)
		return (0);
	if (!data->texture_s)
		return (0);
	return (1);
}

int	get_textures_colors(t_data *data, char **maps)
{
	int	i;
	int	j;

	i = 0;
	while (maps[i] && i < 6)
	{
		j = 0;
		while (maps[i][j] && is_space(maps[i][j]))
			j++;
		handle_element(data, maps[i], j);
		i++;
	}
	if (!check_element(data))
		return (0);
	return (1);
}
