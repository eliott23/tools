/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:10:34 by aababach          #+#    #+#             */
/*   Updated: 2022/11/12 21:53:58 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	g_str;

void	handler(int sig, siginfo_t *inf, void *c)
{
	static int	count = 0;

	(void)c;
	g_str = (g_str * 2) + sig - 30;
	count++;
	if (count == 8)
	{
		count = 0;
		write(1, &g_str, 1);
		g_str = 0;
	}
	usleep(115);
	kill(inf->si_pid, 30);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.__sigaction_u.__sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	putnbr(getpid());
	while (1)
		pause();
}
