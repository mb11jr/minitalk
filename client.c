/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:32:40 by mbentale          #+#    #+#             */
/*   Updated: 2025/03/07 11:03:28 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    ft_send_bits(int pid, unsigned char letter)
{
    unsigned char tmp;
    int i;

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

int main(int ac, char **av)
{
    int server_pid;
    const char *message;
    int i;
    
    if (ac != 3)
    {
        ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./client <server_pid> <message>\033[0m\n");
        exit(1);
    }
    server_pid = ft_atoi(av[1]);
    message = av[2];
    i = 0;
    while (message[i])
        ft_send_bits(server_pid, message[i++]);
    ft_send_bits(server_pid, '\0');
    return (0);
}
