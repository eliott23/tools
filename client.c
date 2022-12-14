/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:01:03 by aababach          #+#    #+#             */
/*   Updated: 2022/11/14 14:15:08 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test(int a)
{
	(void)a;
}

void	ft_init(int *i, int *val, int *bitcount, int argv)
{
	struct sigaction	sa;

	if (argv != 3)
		exit(0);
	sa.__sigaction_u.__sa_handler = test;
	sigaction(SIGUSR1, &sa, NULL);
	*i = 0;
	*val = 0;
	*bitcount = 0;
}

int	main(int argv, char **argc)
{
	int				val;
	int				bitcount;
	int				i;

	ft_init(&i, &val, &bitcount, argv);
	validpid(argc[1]);
	while (argc[2][i])
	{
		bitcount = 7;
		while (bitcount >= 0)
		{
			val = (argc[2][i] >> bitcount) % 2;
			if (val < 0)
				val *= -1;
			kill(ft_atoi(argc[1]), val + 30);
			pause();
			usleep(100);
			bitcount--;
		}
		i++;
	}
}
