/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:22:29 by aababach          #+#    #+#             */
/*   Updated: 2022/11/12 18:31:11 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/proc.h>

void	putstr(char *str)
{
	int	i;
	int	a;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	validpid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
		{
			putstr("UNVALID PID");
			exit(0);
		}
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

int	ft_atoi(char *str)
{
	int	i;
	int	l;
	int	s;
	int	n;

	i = 0;
	s = 1;
	l = 0;
	n = 0;
	if (str[0] == '-')
	{
		s = -1;
		i = 1;
	}
	while (str[l])
		l++;
	if (s == -1)
		l--;
	while (str[i])
	{
		n = (n * 10) + (str[i] - '0');
		i++;
		l--;
	}
	return (n * s);
}

void	test(int a)
{
	a = 0;
}

int	main(int argv, char **argc)
{
	char			*str;
	int				val;
	int				bitcount;
	struct sigaction sa;

	if (argv != 3)
		return (0);
	sa.__sigaction_u.__sa_handler = test;
	sigaction(SIGUSR1, &sa, NULL);
	val = 0;
	bitcount = 0;
	str = (argc[2]);
	validpid(argc[1]);
	int	i = 0;
	int	s_count = 0;
	while (str[i])
	{
		bitcount = 7;
		while (bitcount >= 0)
		{
			val = (str[i]>>bitcount) % 2;
			if (val < 0)
				val *= -1;
			kill(ft_atoi(pid), val + 30);
			s_count++;
			pause();
			usleep(100);
			bitcount--;
		}
		i++;
	}
}
