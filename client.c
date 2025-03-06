/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:32:40 by mbentale          #+#    #+#             */
/*   Updated: 2025/03/06 14:15:58 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    send_signal(int pid, unsigned char letter)
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
        usleep(500);
    }
}

int main(int ac, char **av)
{
    pid_t server_pid;
    const char *message;
    int i;
    
    if (ac != 3)
    {
        ft_printf("Error!");
        exit(1);
    }
    server_pid = ft_atoi(av[1]);
    message = av[2];
    i = 0;
    while (message[i])
        send_signal(server_pid, message[i++]);
    send_signal(server_pid, '\0');
}
