/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:01:16 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/02 12:28:08 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*dest;
	unsigned int		taille;
	unsigned int		i;
	unsigned int		i2;

	i = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	taille = ft_strlen(s);
	if (start > taille)
		len = 0;
	else if (start + len > taille)
		len = taille - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		if (i >= start && i2 < len)
			dest[i2++] = s[i];
		i++;
	}
	dest[i2] = '\0';
	return (dest);
}
