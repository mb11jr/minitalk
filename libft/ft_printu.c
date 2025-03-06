/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentale <mbentale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:43:46 by mbentale          #+#    #+#             */
/*   Updated: 2025/03/06 15:13:49 by mbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printu(unsigned int value, int *count)
{
	if (value >= 10)
		ft_printu(value / 10, count);
	ft_putchar_fd(value % 10 + '0', 1);
	(*count)++;
}
