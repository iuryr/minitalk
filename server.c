/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:07:48 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/26 18:19:37 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <errno.h>
#include <string.h>

void	accumulate_bit(unsigned char *c, unsigned char bit)
{
	*c <<= 1;
	*c = *c | bit;
}

unsigned char *add_to_str(unsigned char *str, unsigned char c, size_t len)
{
	unsigned char *temp;
	int	i;

	i = 0;
	temp = (unsigned char *)ft_strdup((char *)str);
	free(str);
	str = malloc((len + 1) * sizeof(unsigned char));
	if (!str)
		exit(1);
	ft_memcpy(str, temp, len - 1);
	str[len - 1] = c;
	str[len] = '\0';
	free(temp);
	return (str);
}

int		save_to_str(unsigned char c)
{
	static unsigned char *str;
	static size_t	len;

	if (c == '\0')
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
		return (0);
	}
	if (!str)
	{
		str = malloc(2 * sizeof(unsigned char));
		if (!str)
			exit(1);
		str[0] = c;
		str[1] = '\0';
		len = 1;
	}
	else
		str = add_to_str(str, c, ++len);
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int i;
	static unsigned char c;

	if (sig == SIGUSR1)
	{
			i++; // mudar de linha
			accumulate_bit(&c, 0);
			// ft_printf("SIGUSR1 Received from %d\n", info->si_pid);
			// ft_printf("Signals received until now: %i\n", i);
	}
	else if (sig == SIGUSR2)
	{
			i++; // mudar de linha
			accumulate_bit(&c, 1);
			// ft_printf("SIGUSR2 Received from %d\n", info->si_pid);
			// ft_printf("Signals received until now: %i\n", i);
	}
	if (i == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		save_to_str(c);
		i = 0; //reiniciar contagem
	}
	kill(info->si_pid, SIGUSR1);
	context = NULL;
}

int main(void)
{
	pid_t	server_pid;
	struct	sigaction sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGQUIT);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
	ft_printf("Waiting for message...\n");
	while (1)
		pause();
}
