/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:15:14 by mbentale          #+#    #+#             */
/*   Updated: 2025/03/09 08:10:56 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_send_bits(int pid, unsigned char letter)
{
	unsigned char	tmp;
	int				i;

	i = 8;
	tmp = letter;
	while (i > 0)
	{
		i--;
		tmp = letter >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(30);
	}
}

void	received_msg(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("\n\033[32mMessage received successfully!\033[0m ✅\n");
}

int	main(int ac, char **av)
{
	int			server_pid;
	const char	*message;
	int			i;

	signal(SIGUSR1, received_msg);
	if (ac == 3)
	{
		server_pid = ft_strict_atoi(av[1]);
		if (server_pid == -1 || server_pid == 0)
		{
			ft_printf("\033[91mWrong format input for <server_pid>.\033[0m\n");
			exit(1);
		}
		message = av[2];
		i = 0;
		while (message[i])
			ft_send_bits(server_pid, message[i++]);
		ft_send_bits(server_pid, '\0');
	}
	else
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <server_pid> <message>\033[0m\n");
		exit(1);
	}
}
