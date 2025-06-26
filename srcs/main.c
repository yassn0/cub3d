/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 07:33:05 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/27 00:37:09 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_free_error(char *str, t_data *data)
{
	if (data && data->tmp_map)
		free_map(data->tmp_map);
	printf("%s", str);
	exit(1);
}

void	init_struct(t_data *data)
{
	data->texture_N = NULL;	
	data->texture_S = NULL;	
	data->texture_E = NULL;	
	data->texture_W = NULL;	
	data->floor_color = NULL;	
	data->sky_color = NULL;	
	data->tmp_map = NULL;	
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)env;
	init_struct(&data);
	if (ac != 2)
		exit_free_error("Wromg number of arguments\n", NULL);
	if (!map_ok(av[1], &data))
		exit_free_error("Error\nmap or file not valid\n", &data);
	// if (!init_window(&data))
	// 	exit_free_error("Error lib mlx\n", &data);

	// mlx_hook(data.window, 17, 1, &close_window_cross, &data);
	// mlx_loop(data.mlx);
	
	// destroy_all(data);
	free_map(data.tmp_map);
	return (0);
}
