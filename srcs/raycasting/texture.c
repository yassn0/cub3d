/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:00:00 by yfradj            #+#    #+#             */
/*   Updated: 2025/07/05 08:43:52 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	load_single_texture(t_data *data, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
		return (0);
	tex->data = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line,
			&tex->endian);
	return (1);
}

int	load_textures(t_data *data)
{
	if (!load_single_texture(data, &data->textures[0], data->texture_n))
		return (0);
	if (!load_single_texture(data, &data->textures[1], data->texture_s))
		return (0);
	if (!load_single_texture(data, &data->textures[2], data->texture_w))
		return (0);
	if (!load_single_texture(data, &data->textures[3], data->texture_e))
		return (0);
	return (1);
}

int	get_texture_pixel(t_texture *tex, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->data + (y * tex->size_line + x * (tex->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}
