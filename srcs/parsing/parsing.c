/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 08:36:27 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/23 17:19:03 by yfradj           ###   ########.fr       */
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
		return (0);
	return (1);
}

/*mets les donnees du fichier dans la structure
a finir plus tard parce que ils peuvent etre mis dans un ordre different*/
int	split_info_map(char *buffer, t_data *data)
{
	char	**maps;

	maps = ft_split(buffer, '\n');
	if (!maps)
		return (0);
	free(buffer);
	if (maps[0] && ft_strlen(maps[0]) > 3 && maps[1] && ft_strlen(maps[1]) > 3
		&& maps[2] && ft_strlen(maps[2]) > 3 && maps[3]
		&& ft_strlen(maps[3]) > 3 && maps[4] && ft_strlen(maps[4]) > 2
		&& maps[5] && ft_strlen(maps[5]) > 2)
	{
		data->texture_N = &maps[0][3];
		data->texture_S = &maps[1][3];
		data->texture_W = &maps[2][3];
		data->texture_E = &maps[3][3];
		data->ground_color = &maps[4][2];
		data->sky_color = &maps[5][2];
	}
	else
		return (0);
	if (maps[6])
		data->map = &maps[6];
	return (1);
}

/* vérifie si la map donne est bonne */
int	map_ok(char *file_map, t_data *data)
{
	int		fd;
	char	*buffer;
	char	**maps;

	fd = open(file_map, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!cub_file(file_map))
		return (0);
	buffer = get_map_gnl(fd);
	// printf("%s", buffer);
	if (!split_info_map(buffer, data))
		return (0);
	if (!check(data))
		return (0);
	print_data(data);
	return (1);
}
