/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:36:27 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 08:44:39 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_max_len(t_data *data)
{
	int	i;
	int	max_len;
	int	current_len;

	i = 0;
	max_len = 0;
	while (data->map[i])
	{
		current_len = 0;
		while (data->map[i][current_len] && data->map[i][current_len] != '\n')
			current_len++;
		if (current_len > max_len)
			max_len = current_len;
		i++;
	}
	return (max_len);
}

static char	*create_normalized_line(char *old_line, int max_len)
{
	char	*new_line;
	int		j;
	int		current_len;

	current_len = 0;
	while (old_line[current_len] && old_line[current_len] != '\n')
		current_len++;
	new_line = malloc(max_len + 1);
	if (!new_line)
		return (NULL);
	j = 0;
	while (j < current_len && old_line[j] && old_line[j] != '\n')
	{
		if (old_line[j] == ' ')
			new_line[j] = '1';
		else
			new_line[j] = old_line[j];
		j++;
	}
	while (j < max_len)
		new_line[j++] = '1';
	new_line[max_len] = '\0';
	return (new_line);
}

int	replace_space(t_data *data)
{
	int		i;
	int		max_len;
	char	*new_line;

	max_len = get_max_len(data);
	i = 0;
	while (data->map[i])
	{
		new_line = create_normalized_line(data->map[i], max_len);
		if (!new_line)
			return (0);
		free(data->map[i]);
		data->map[i] = new_line;
		i++;
	}
	return (1);
}

int	close_by_wall_side(t_data *data)
{
	int	start;
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		start = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
			j++;
		if (j < 1)
			return (0);
		while (is_space(data->map[i][start]))
			start++;
		if (data->map[i][start] != '1' || data->map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	close_by_wall_topdown(t_data *data)
{
	int	i;
	int	height;

	i = 0;
	height = height_map(data->map);
	while (data->map[0][i] && data->map[0][i] != '\n')
	{
		if (data->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (data->map[height - 1][i] && data->map[height - 1][i] != '\n')
	{
		if (data->map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
