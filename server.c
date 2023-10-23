/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iusantos <iusantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:07:48 by iusantos          #+#    #+#             */
/*   Updated: 2023/10/23 16:34:43 by iusantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	pid_t	server_pid;

	server_pid = getpid();
	ft_printf("Server PID: %d\n", server_pid);
}
