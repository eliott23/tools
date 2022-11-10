#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/proc.h>

char    str;

void    putstr(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i],1);
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
    static int count = 0;

    str = (str * 2) + sig - 30;
    // fprintf(stderr, "\nthis is the signal %d\n",sig);
    // fprintf(stderr,"\nthis is the value %d ",str);
    count++;
    if (count == 8)
    {
        count = 0;
        // fprintf(stderr,"\nthis is the final value %d ",str);
        write(1, &str, 1);
        str = 0;
    }
}

int main()
{
    signal(SIGUSR1,test);
    signal(SIGUSR2,test);
    putnbr(getpid());
    while (1)
        pause();
}