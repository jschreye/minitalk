/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:33:21 by jschreye          #+#    #+#             */
/*   Updated: 2021/10/26 11:13:23 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*int	ft_nbrmot(char *s, char c)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c))
			i2++;
		i++;
	}
	return (i2);
}
*/
char	**ft_split_suite(char **tab, int index);

static size_t	count_strs(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t		tab[2];
	const char	*start;
	char		**split;

	if (!s)
		return (NULL);
	split = (char **) malloc(((count_strs(s, c)) + 1) * sizeof(*split));
	if (!split)
		return (NULL);
	tab[1] = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		start = s;
		tab[0] = 0;
		while (*s && *s != c)
		{
			s++;
			tab[0]++;
		}
		if (*(s - 1) != c)
			split[tab[1]++] = ft_substr(start, 0, tab[0]);
	}
	return (ft_split_suite(split, tab[1]));
}

char	**ft_split_suite(char **tab, int index)
{
	tab[index] = 0;
	return (tab);
}
// len = tab[0]
// index = tab[1]
