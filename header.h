#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/proc.h>

void	putstr(char *str);
void	validpid(char *pid);
void	putnbr(int n);
int		ft_atoi(char *str);

#endif
