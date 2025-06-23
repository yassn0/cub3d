/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:30:22 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/23 17:17:52 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_space(char c)
{
	if (c && (c == ' '))
		return (1);
	return (0);
}

int	height_map(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	return (i);
}

int	character_condition(t_data *data, int i, int j, int *count)
{
	if (data->map[i][j] != '0' && data->map[i][j] != '1'
		&& data->map[i][j] != 'N' && data->map[i][j] != 'S'
		&& data->map[i][j] != 'E' && data->map[i][j] != 'W')
		return (0);
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
	{
		data->player_orientation = data->map[i][j];
		data->p_x = j;
		data->p_y = i;
		(*count)++;
	}
}

int	len_max_row(t_data *data)
{
	int i;
	int j;
	int len_max;

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