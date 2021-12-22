/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:51:25 by jschreye          #+#    #+#             */
/*   Updated: 2021/12/22 09:55:16 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	truc(int pid, char *str, size_t len) 
{
	size_t	i;
	int		j;

	i = 0;
	while(i <= len)
	{
		j = 0;
		while(j < 7)
		{
			if((str[i] >> j + 1) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(600);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pis = ft_atoi(argv[1]);
		truc(pid, argv[2], ft_strlen(argv[2]));	
	}
	else
		t_putstr("usage: \n");
	return (0);
}
