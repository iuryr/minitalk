/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:07:48 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/23 18:49:37 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int i;

	if (sig == SIGUSR1)
	{
			i++; // mudar de linha
			//accumulate bit
			ft_printf("SIGUSR1 Received from %d\n", info->si_pid);
			ft_printf("Signals received until now: %i\n", i);
			// kill(info->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
			i++; // mudar de linha
			//accumulate bit
			ft_printf("SIGUSR2 Received from %d\n", info->si_pid);
			ft_printf("Signals received until now: %i\n", i);
			// kill(info->si_pid, SIGUSR1);
	}
	if (i == 8)
	{
		//colocar bit acumulado na string
		i = 0; //reiniciar contagem
	}
	context = NULL;
}

void	accumulate_bit(unsigned char *c, unsigned char bit)
{

}

int main(void)
{
	pid_t	server_pid;
	struct	sigaction sa;
	static	unsigned char c;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	ft_printf("Waiting for message...\n");
	while (1)
		pause();
}
