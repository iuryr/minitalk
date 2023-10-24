/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:07:48 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/24 19:34:01 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	accumulate_bit(unsigned char *c, unsigned char bit)
{
	*c <<= 1;
	*c = *c | bit;
}

int		add_to_str(unsigned char *str, unsigned char c)
{
	unsigned char *temp;
	static size_t	size;

	size = 2;
	if (!str)
	{
		str = malloc(2 * sizeof(unsigned char));
		if (!str)
			return(1);
		else
		{
			str[0] = c;
			str[1] = '\0';
		}
	}
	else
	{
		temp = str;
		str = malloc(++size * sizeof(unsigned char));
		if (!str)
			return(1);
		ft_memcpy(str, temp, size - 2);
		str[size - 1] = c;
		str[size] = '\0';
		free(temp);
	}
	return (0);
}

int		save_to_str(unsigned char *str, unsigned char c)
{
	if (c == '\0')
		ft_printf("%s\n", str);
	else
		add_to_str(str, c);
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int i;
	static unsigned char c;
	static unsigned char *str;

	if (sig == SIGUSR1)
	{
			i++; // mudar de linha
			accumulate_bit(&c, 0);
			ft_printf("SIGUSR1 Received from %d\n", info->si_pid);
			ft_printf("Signals received until now: %i\n", i);
			// kill(info->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
			i++; // mudar de linha
			accumulate_bit(&c, 1);
			ft_printf("SIGUSR2 Received from %d\n", info->si_pid);
			ft_printf("Signals received until now: %i\n", i);
			// kill(info->si_pid, SIGUSR1);
	}
	if (i == 8)
	{
		save_to_str(str, c);
		i = 0; //reiniciar contagem
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
