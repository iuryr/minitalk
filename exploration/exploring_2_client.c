#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	sigusr1_handler(int signum, siginfo_t *info, void *)
{
	if (signum == SIGUSR1)
		printf("SIGUSR1 Received from process %d\n", info->si_pid);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (-1);

	struct sigaction sa;
	sa.sa_sigaction = sigusr1_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);

	printf("Sending first signal...\n");
	sleep(1);
	kill(atoi(argv[1]), SIGUSR1);
	while(1)
	{
		printf("Waiting for ack signal..\n");
		sleep(1);
		kill(atoi(argv[1]), SIGUSR1);
		pause();
	}
}
