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
			|| base[fwd] < 32 || base[fwd] > 126)
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
	int	base_s;

	base_s = ft_strlen(base);
	if (ft_basecontrol(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
		}
		if (nbr < base_s)
			write(1, &base[nbr], 1);
		else if (nbr >= base_s)
		{
			ft_putnbr_base(nbr / base_s, base);
			ft_putnbr_base(nbr % base_s, base);
		}
	}
}

/*int main()
{
	ft_putnbr_base(-134535, "0123456789ABCDEF");
}*/
