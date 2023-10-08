#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	sigusr1_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("SIGUSR1 Received!\n");
}

int main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %i\n", pid);

	struct sigaction sa;
	sa.sa_handler = sigusr1_handler; //indicando nossa funcao que vai lidar com o sinal
	sa.sa_flags = 0; //avisando que nosso processo deve executar a signal handler de maneira "padrao"
	sigemptyset(&sa.sa_mask); //inicializando o sa_mask para vazio, ou seja, nao ha sinais para serem bloqueados.
	
	sigaction(SIGUSR1, &sa, NULL); //registrando novo act para lidar com sinal SIGUSR1
	
	while (1)
	{
		printf("Process %i waiting for signal.\n", pid);
		sleep(1);
	}
	return (0);
}
