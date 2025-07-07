/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 07:33:05 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 07:51:01 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_space(char c)
{
	if (c && (c == ' '))
		return (1);
	return (0);
}

void	exit_free_error(char *str, t_data *data)
{
	if (data && data->tmp_map)
		free_map(data->tmp_map);
	printf("%s", str);
	exit(1);
}

void	init_struct(t_data *data)
{
	data->texture_n = NULL;
	data->texture_s = NULL;
	data->texture_e = NULL;
	data->texture_w = NULL;
	data->floor_color = NULL;
	data->sky_color = NULL;
	data->tmp_map = NULL;
	data->img = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	init_struct(&data);
	if (ac != 2)
		exit_free_error("Wrong number of arguments\n", NULL);
	if (!map_ok(av[1], &data))
		exit_free_error("Error\nmap or file not valid\n", &data);
	if (!init_window(&data))
		exit_free_error("Error lib mlx\n", &data);
	if (!init_raycasting(&data))
		exit_free_error("Error raycasting init\n", &data);
	render_frame(&data);
	mlx_hook(data.window, 17, 1, &close_window_cross, &data);
	mlx_hook(data.window, 2, 1, &handle_keypress, &data);
	mlx_loop(data.mlx);
	return (0);
}
