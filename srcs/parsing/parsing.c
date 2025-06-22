/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 08:36:27 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/19 13:48:44 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*get_map_gnl(int fd)
{
	char	*line;
	char	*map;
	char	*tmp;

	map = NULL;
	tmp = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!map)
			map = line;
		else
		{
			tmp = map;
			map = ft_strjoin(map, line);
			free(tmp);
			free(line);
			if (!map)
				return (close(fd), NULL);
		}
		line = get_next_line(fd);
	}
	return (close(fd), map);
}

int	cub_file(char *name)
{
	int	i;

	i = ft_strlen(name);
	i = i - 4;
	if (i < 0)
		return (1);
	if (name[i] != '.' || name[i + 1] != 'c' || name[i + 2] != 'u' || name[i
			+ 3] != 'b')
		return (1);
	return (0);
}

/* vérifie si la map donne est bonne */
int	map_ok(char *file_map)
{
	int		fd;
	char	*buffer;
	char	**map;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!cub_file(file_map))
		return (0);
	buffer = get_map_gnl(fd);
	printf("%s", buffer);
	// map = ft_split(buffer, '\n');
	// if (!check(map))
	// 	return (0);
	return (1);
}
