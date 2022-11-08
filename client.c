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
int ft_atoi(char *str)
{
    int i;
    int s;

    i = 0;
    s = 1;
    if (str[0] == '-')
    {
        s = -1;
        i = 1;
    }
}
int main(int argv, char **argc)
{
    char *str = argc[1];
    putstr(str);
    write(1, "\n", 1);
    printf("this is the size %ld",sizeof(pid_t));
    // printf("%d\n", PID_MAX);
}

// int main()
// {
//   printf ("Before Forking\n");
//   fork();
//   printf ("After Forking\n");
// }