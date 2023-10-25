/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:25:13 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/25 15:03:49 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
	{
			ft_printf("SIGUSR1 (ACK) Received from %d\n", info->si_pid);
	}
	context = NULL;
}


int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	struct	sigaction sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGQUIT);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR2);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR2);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR2);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR2);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR2);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR2);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
	kill(ft_atoi(argv[1]), SIGUSR1);
	pause();
}
