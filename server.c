/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:32:44 by mbentale          #+#    #+#             */
/*   Updated: 2025/03/07 10:54:28 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    signal_handler(int signal)
{
    static unsigned char character;
    static int bit_index;

    character <<= 1;
    character |= (signal == SIGUSR1);
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

int main(int ac, char **av)
{
    int pid;

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
    while (1)
    {
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);
        pause();
    }
}
