/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 07:28:27 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/23 17:13:57 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data
{
	char	**map;
	char	*texture_N;
	char	*texture_S;
	char	*texture_W;
	char	*texture_E;
	char	*ground_color;
	char	*sky_color;
	char	player_orientation;
	int		p_x;
	int		p_y;
}			t_data;

/*parsing*/
int			map_ok(char *file_map, t_data *data);
int			check(t_data *data);
int			character_condition(t_data *data, int i, int j, int *count);

/*utils*/
int			is_space(char c);
int			height_map(char **tab);

/*debug*/
void		print_tab(char **tab);
void		print_data(t_data *data);

#endif