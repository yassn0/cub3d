/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 07:33:05 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/24 01:07:43 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_error(char *str)
{
	printf("%s", str);
	exit(1);
}

void	exit_free_error(char *str, t_data *data)
{
	free_map(data->tmp_map);
	printf("%s", str);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void)env;
	if (ac != 2)
		exit_error("Wromg number of arguments\n");
	if (!map_ok(av[1], &data))
		exit_free_error("Error\nmap or file not valid\n", &data);
	if (!init_window(&data))
		exit_free_error("Error lib mlx\n", &data);
		
	mlx_hook(data.window, 17, 1, &close_window_cross, &data);
	mlx_loop(data.mlx);
	
	destroy_all(data);
	free_map(data.tmp_map);
	return (0);
}
