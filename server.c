#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/proc.h>

char    str;
int     b_count;

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

void    test(int sig, siginfo_t *inf, void *c)
{
    static int count = 0;

    // printf("this is the source pid %d\n",inf->si_pid);
    str = (str * 2) + sig - 30;
    b_count++;
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
    usleep(80);
    kill(inf->si_pid, 30);
}

int main()
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    // sa.__sigaction_u.__sa_handler = &test;
    sa.__sigaction_u.__sa_sigaction = &test;
    // signal(SIGUSR1,test);
    // signal(SIGUSR2,test);
    sigaction(SIGUSR1,&sa,NULL);
    sigaction(SIGUSR2,&sa,NULL);
    putnbr(getpid());
    while (1)
    {
        pause();
        // printf("this is the b_count %d\n",b_count);
    }
}