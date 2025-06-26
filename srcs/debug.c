/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:49:48 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/27 00:09:40 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("Map:\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	print_data(t_data *data)
{
	print_tab(data->map);
	printf("texture: %s\n", data->texture_N);
	printf("texture: %s\n", data->texture_S);
	printf("texture: %s\n", data->texture_W);
	printf("texture: %s\n", data->texture_E);
	printf("color: %s\n", data->floor_color);
	printf("color: %s\n", data->sky_color);
	printf("orientation: %c\n", data->player_orientation);
	printf("p_x: %d\n", data->p_x);
	printf("p_y: %d\n", data->p_y);
}