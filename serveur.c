/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:52:03 by jschreye          #+#    #+#             */
/*   Updated: 2022/01/04 14:51:08 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

static t_msg	g_msg;

void	ft_returnsignal(int bit)
{
	g_msg.c += ((bit & 1) << g_msg.size);
	g_msg.size++;
	if (g_msg.size == 7)
	{
		write(1, &g_msg.c, 1);
		if (!g_msg.c)
			write(1, "\n", 1);
		g_msg.c = 0;
		g_msg.size = 0;
	}
}

int	main(void)
{
	g_msg.c = 0;
	g_msg.size = 0;
	ft_putnbrnbr(getpid());
	write(1, "\n", 1);
	ft_putstr("message: ");
	while (1)
	{
		signal(SIGUSR2, ft_returnsignal);
		signal(SIGUSR1, ft_returnsignal);
		pause();
	}
	return (0);
}
