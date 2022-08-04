/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 01:55:47 by isaridas          #+#    #+#             */
/*   Updated: 2022/08/02 11:56:34 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb / 10 > 0)
	{
		ft_putnbr(nb / 10);
		ft_putchar('0' + (nb % 10));
	}
	else if (nb == -2147483648)
		write(1, "-2147483648", 12);
	else if (nb < 0 && nb != -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
		ft_putchar('0' + (nb % 10));
}
