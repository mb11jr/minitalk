/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:32:44 by mbentale          #+#    #+#             */
/*   Updated: 2025/03/08 23:20:32 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char character;
	static int bit_index;
	static int last_pid;

	(void)context;
	if (last_pid != info->si_pid)
	{
		last_pid = info->si_pid;
		character = 0;
		bit_index = 0;
		ft_printf("\n\033[33mNew client detected. Restarting message...\033[0m\n");
	}
	character <<= 1;
	character |= (signum == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (character == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", character);
		bit_index = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction sa;
	int	pid;

	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	(void)av;
	if (ac != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		exit(1);
	}
	pid = getpid();
	ft_printf("\033[36mPID\033[0m \033[36m->\033[0m %d\n", pid);
	ft_printf("\033[94mWaiting for a message...\033[0m\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
}
