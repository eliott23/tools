#include "header.h"

void	putstr(char *str)
{
	int	i;

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
