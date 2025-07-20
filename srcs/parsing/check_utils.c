/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibarahim <ibarahim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:10:41 by ibarahim          #+#    #+#             */
/*   Updated: 2025/07/20 15:10:41 by ibarahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_character(t_data *data)
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

int	check_same_length(t_data *data)
{
	int	i;
	int	first_len;
	int	len;

	i = 0;
	first_len = 0;
	while (data->map[i])
	{
		len = 0;
		while (data->map[i][len] && data->map[i][len] != '\n')
			len++;
		if (i == 0)
			first_len = len;
		else if (len != first_len)
			return (0);
		i++;
	}
	return (1);
}

int	check(t_data *data)
{
	if (!data->map)
		return (0);
	if (!check_character(data))
		return (0);
	if (!replace_space(data))
		return (0);
	if (!check_same_length(data))
		return (0);
	if (!close_by_wall_side(data))
		return (0);
	if (!close_by_wall_topdown(data))
		return (0);
	return (1);
}
