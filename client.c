/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:25:13 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/26 16:11:02 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	next_bit(unsigned char *str)
{
	static unsigned char *msg;
	static int	bit_index;
	unsigned char	c;
	unsigned char	bit;

	if (msg == NULL)
		msg = str;
	c = *msg << bit_index;
	bit = c & 0x80;
	if (bit_index++ == 7)
	{
		bit_index = 0;
		msg++;
	}
	return (bit);
}

void	send_bit(unsigned char bit, int pid)
{
	static int server_pid;

	if (server_pid == 0)
		server_pid = pid;
	if (bit == 0x80)
		kill(server_pid, SIGUSR2);
	else
		kill(server_pid, SIGUSR1);
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		send_bit((next_bit((unsigned char *)"whatever")), 1);
	else if (signum == SIGUSR2)
	{
		ft_printf("Message fully transmited. Bye-bye.\n");
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("Usage: ./client server_pid string\n");
		return (1);
	}
	signal(SIGUSR1, &signal_handler);
	signal(SIGUSR2, &signal_handler);
	send_bit(next_bit((unsigned char *)argv[2]), ft_atoi(argv[1]));
	while(1)
		pause();
}
