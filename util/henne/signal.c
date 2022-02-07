#include "../../minishell.h"

void	sighandler(int sigbit, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	if (sigbit == SIGINT)
	{
		printf("\n");
		prompt();
	}
	else if (sigbit == SIGQUIT)
		exit(0);
}

void	init_sig(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sighandler;
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}
