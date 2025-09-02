/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:31:29 by yfradj            #+#    #+#             */
/*   Updated: 2025/06/23 15:55:22 by yfradj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_mot(const char *str, char c)
{
	int	i;
	int	boul;
	int	count;

	i = 0;
	boul = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] != c && boul == 0)
		{
			count++;
			boul = 1;
		}
		else if (str[i] == c && boul == 1)
			boul = 0;
		i++;
	}
	return (count);
}

static char	*ft_strdup_ind(const char *str, int deb, int fin)
{
	char	*cpy;
	int		i;

	cpy = malloc((fin - deb + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	i = 0;
	while (deb < fin)
	{
		cpy[i++] = str[deb];
		deb++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static void	*free_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_split_loop(char const *s, char c, char **split)
{
	int	i;
	int	j;
	int	index;

	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen((char *)s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen((char *)s)) && index >= 0)
		{
			split[j] = ft_strdup_ind(s, index, i);
			if (!(split[j++]))
				return (free_tab(split, j));
			index = -1;
		}
	}
	return (split[j] = NULL, split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc((nb_mot(s, c) + 1) * sizeof(char *));
	if (!(split))
		return (0);
	if (nb_mot(s, c) == 0)
		return (split[0] = NULL, split);
	return (ft_split_loop(s, c, split));
}

// int	main(void)
// {
// 	int i = 0;
// 	char **split;
// 	char str[] = "Bonjour, ca va    a ";
// 	char sep = ' ';
// 	split = ft_split(str, sep);
// 	printf("%d\n", nb_mot(str, ' '));
// 	i++;

// 	return (0);
// }