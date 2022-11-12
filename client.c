/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:36:24 by aababach          #+#    #+#             */
/*   Updated: 2022/11/12 21:53:47 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aababach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:22:29 by aababach          #+#    #+#             */
/*   Updated: 2022/11/12 20:44:06 by aababach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	test(int a)
{
	(void)a;
}

void	ft_init(void)
{
	struct sigaction	sa;

	sa.__sigaction_u.__sa_handler = test;
	sigaction(SIGUSR1, &sa, NULL);
}

int	main(int argv, char **argc)
{
	char			*str;
	int				val;
	int				bitcount;
	int				i;

	i = 0;
	ft_init();
	if (argv != 3)
		return (0);
	val = 0;
	bitcount = 0;
	str = (argc[2]);
	validpid(argc[1]);
	while (str[i])
	{
		bitcount = 7;
		while (bitcount >= 0)
		{
			val = (str[i] >> bitcount) % 2;
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
