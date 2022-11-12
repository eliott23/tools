/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:10:34 by aababach          #+#    #+#             */
/*   Updated: 2022/11/12 18:14:25 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/proc.h>

char	g_str;

void	putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	putnbr(int n)
{
	char	a;

	a = 0;
	if (n > 9)
		putnbr(n / 10);
	a = n % 10 + '0';
	write(1, &a, 1);
}

void	test(int sig, siginfo_t *inf, void *c)
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
	sa.__sigaction_u.__sa_sigaction = &test;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	putnbr(getpid());
	while (1)
		pause();
}
