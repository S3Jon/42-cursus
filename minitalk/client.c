#include "minitalk.h"

/*
	we shall know WHEN the server has recieved and handled the sent kill once it tells us it's done
	no more collisions :D
*/
int	g_reply = 1;

void	ft_handler(int signal, siginfo_t *a, void *b)
{
	(void)a;
	(void)b;
	if (signal == SIGUSR1)
		g_reply = 0;
}

void	ft_sendmsg(int id, char *msg)
{
	char	act;
	int		i;
	int		k;

	k = 0;
	while (msg[k] != '\0')
	{
        act = msg[k];
		i = 7;
		while (i >= 0)
		{
			g_reply = 1;
			if ((act >> i) & 1)

				kill(id, SIGUSR2);
			else
				kill(id, SIGUSR1);
            i--;
            while(g_reply == 1)
				usleep(1);
		}
		k++;
	}
}

/*
	sigaction args:
		1- signal tipe (SIGUSR1/2 in this case)
		2- struct sigaction:
			-handler: set a default behavior or a handler funct -> ft_handler to handle kill replies
			-mask: signals to be blocked -> none || sigemptyset?
			-sa_flags: flags for behavior; SA_SIGINFO reviece additional info for when a signal is sent
		3- where to return old handler info // NULL

	https://www.youtube.com/watch?v=_1TuZUbCnX0
	https://man7.org/linux/man-pages/man2/sigaction.2.html
	https://www.gnu.org/software/libc/manual/html_node/Flags-for-Sigaction.html
	https://sites.uclouvain.be/SystInfo/usr/include/asm-generic/signal.h.html
	chatgpt
*/

//Should add a SIGUSR1/2 error checker
int	main(int argc, char **argv)
{
	struct sigaction	sigcli;
	int					pid;

	if (argc != 3)
		return (0);
	else
	{
		pid = ft_atoi(argv[1]);
		sigcli.sa_sigaction = &ft_handler;
		sigemptyset(&sigcli.sa_mask);
		sigcli.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sigcli, NULL) == -1 || sigaction(SIGUSR2, &sigcli, NULL) == -1)
			exit(EXIT_FAILURE);
		ft_sendmsg(pid, argv[2]);		
	}
	return (0);
}
