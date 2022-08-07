/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:11:53 by isaridas          #+#    #+#             */
/*   Updated: 2022/08/06 20:32:45 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *base)
{
	int	size;

	size = 0;
	while (base[size])
		size++;
	return (size);
}

int	ft_basecontrol(char *base)
{
	int	fwd;
	int	snd;

	if (ft_strlen(base) < 2)
		return (0);
	fwd = 0;
	while (base[fwd])
	{
		if (base[fwd] == '-' || base[fwd] == '+'
			|| base[fwd] < 33 || base[fwd] > 126)
			return (0);
		snd = fwd + 1;
		while (base[snd])
		{
			if (base[fwd] == base[snd])
				return (0);
			snd++;
		}
		fwd++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	base_s;
	long int	nb;

	base_s = ft_strlen(base);
	nb = nbr;
	if (ft_basecontrol(base))
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb < base_s)
			write(1, &base[nb], 1);
		if (nb >= base_s)
		{
			ft_putnbr_base(nb / base_s, base);
			ft_putnbr_base(nb % base_s, base);
		}
	}
}
