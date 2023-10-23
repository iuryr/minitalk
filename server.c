/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:07:48 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/23 17:31:27 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
	{
			ft_printf("SIGUSR1 Received from %d\n", info->si_pid);
	}
	else if (sig == SIGUSR2)
	{
			ft_printf("SIGUSR2 Received from %d\n", info->si_pid);
	}
	context = NULL;
}

int main(void)
{
	pid_t	server_pid;
	struct	sigaction sa;

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
