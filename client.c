/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:51:25 by jschreye          #+#    #+#             */
/*   Updated: 2022/01/04 15:12:18 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_signal(int pid, char *str, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	while (i <= len)
	{
		j = 0;
		while (j < 7)
		{
			if ((str[i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j++;
			usleep(600);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_signal(pid, argv[2], ft_strlen(argv[2]));
	}
	else
		ft_putstr("usage: ho nnnnnnnnnnnnnnooooooooooooooooooo\n");
	return (0);
}
