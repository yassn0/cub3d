/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 07:33:05 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/18 14:43:56 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_error(char *str)
{
	printf("%s", str);
	exit(1);
	
}

void	exit_free_error(char *str)
{
	printf("%s", str);
	exit(1);
	
}

int	main(int ac, char **av, char **env)
{
	if (ac != 2)
		exit_error("Wromg number of arguments\n");
	
	if (!map_ok(av[1]))
		exit_error("Error\nmap not valid\n");
	return (0);
}
