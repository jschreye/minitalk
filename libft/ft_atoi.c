/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:58:50 by jschreye          #+#    #+#             */
/*   Updated: 2021/11/04 13:55:17 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_white_space(char *c)
{
	if (*c == '\n' || *c == '\t' || *c == '\r'
		|| *c == '\v' || *c == '\f' || *c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		a;
	int		b;
	char	*p;

	a = 1;
	b = 0;
	p = (char *)str;
	while (is_white_space(p))
		p++;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			a *= -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		b *= 10;
		b += (*p - '0');
		p++;
	}
	return (a * b);
}
