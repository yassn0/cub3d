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

static int	replace_space(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (data->map[i][j] == ' ')
				data->map[i][j] = '1';
			j++;
		}
		i++;
	}
	return (1);
}

static int	close_by_wall_side(t_data *data)
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
		if (j <= 2)
			return (0);
		while (is_space(data->map[i][start]))
			start++;
		if (data->map[i][start] != '1' || data->map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	close_by_wall_topdown(t_data *data)
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

static int	check_character(t_data *data)
{
	int	i;
	int	j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] && data->map[i][j] != '\n')
		{
			if (!character_condition(data, i, j, &count_player))
				return (0);
			j++;
		}
		i++;
	}
	if (count_player != 1)
		return (0);
	return (1);
}

int	check(t_data *data)
{
	if (!check_character(data))
		return (0);
	if (!replace_space(data))
		return (0);
	if (!close_by_wall_side(data))
		return (0);
	if (!close_by_wall_topdown(data))
		return (0);
	return (1);
}
