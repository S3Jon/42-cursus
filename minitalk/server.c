#include "minitalk.h"

void    ft_handler(int signal, siginfo_t *data, void *extra)
{
	static int  i = 0;
	static char c = 0;

	(void)extra;
	if (i >= 8 || i < 0 || !i)
		i = 0;
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		c = c << 1;
		if (signal == SIGUSR2)
			c |= 1;
	}
	i++;
	if (i >= 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	if(kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_putstr_fd("Sigaction error\n");
		return ;
	}
}

int main(void)
{
	struct sigaction	sigsv;

	sigsv.sa_sigaction = &ft_handler;
	sigemptyset(&sigsv.sa_mask);
	sigsv.sa_flags = SA_NODEFER;
    ft_putstr_fd("Minitalk server\nPID: ", 1);
    ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	if (sigaction(SIGUSR1, &sigsv, NULL) == -1 || sigaction(SIGUSR2, &sigsv, NULL) == -1)
	{
		ft_putstr_fd("Sigaction error\n");
		return(-1);
	}
    while(1)
    {
        pause();
    }
    return (1);
}
