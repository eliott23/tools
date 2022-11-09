#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/proc.h>

void    putstr(char *str)
{
    int i;
    int a;

    i = 0;
    while (str[i])
    {
        write(1, &str[i],1);
        a = 0;
        while (a < 16)
        {
            printf("%d\n", str[i]>>a);
            a++;
        }
        printf("i incremented 😭\n");
        i++;
    }
}

void    validpid(char *pid)
{
    int i = 0;
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

void    putnbr(int n)
{
    char a;

    a = 0;
    if (n > 9)
        putnbr(n / 10);
    a = n % 10 + '0';
    write(1, &a,1);
}

int ft_atoi(char *str)
{
    int i;
    int l;
    int s;
    int n;

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

int main(int argv, char **argc)
{
    char    *pid;
    char    *str;
    int bitcount;

    bitcount = 0;
    pid = argc[1];
    str = (argc[2]);
    putstr(str);
    // printf("")
    validpid(pid);
    int i = 0;
    // while (str[i])
    // {
    //     bitcount = 0;
    //     while (bitcount < 16)
    //     {
    //         printf("this is i %d\n",i);
    //         printf("this is the number %d\n", (str[i]>>bitcount));
    //         kill(ft_atoi(pid),(((str[i]>>bitcount) % 2) + 30));
    //         // kill(ft_atoi(pid),(30));
    //         usleep(50);
    //         bitcount++;
    //     }
    //     i++;
    // }
}