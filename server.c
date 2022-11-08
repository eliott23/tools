#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/proc.h>

void    putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i],1);
        i++;
    }
}

void    putnbr(int n)
{
    char a;

    a = 0;
    if (n > 9)
        putnbr(n / 10);
    a = n % 10 + '0';
    write(1, &a,1);
}

void    test(int sig)
{
    printf("the least significant bit %d\n", sig - 30);
}

int main()
{
    signal(SIGUSR1,test);
    signal(SIGUSR2,test);
    putnbr(getpid());
    write(1, "\n", 1);
    while (1);
}