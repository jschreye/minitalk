/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:59:54 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/24 14:23:05 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dest;

	size = ft_strlen(s1) + 1;
	dest = malloc(size * sizeof(*dest));
	if (dest == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	*dest = '\0';
	return (dest - size + 1);
}
