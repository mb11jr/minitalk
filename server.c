/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:32:44 by mbentale          #+#    #+#             */
/*   Updated: 2025/03/06 14:30:56 by mbentale         ###   ########.fr       */
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

int main()
{
    ft_printf("%d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1)
        pause();
}
