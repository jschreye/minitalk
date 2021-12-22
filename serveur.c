/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:52:03 by jschreye          #+#    #+#             */
/*   Updated: 2021/12/17 09:11:05 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	int pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		while (1)
		{
			printf ("quelque chose\n");
			usleep(50000);
		}
	else
	{
		sleep(10);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return (0);
}
