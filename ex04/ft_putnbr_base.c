/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:11:53 by isaridas          #+#    #+#             */
/*   Updated: 2022/07/31 20:08:00 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *base)
{
	int size;

	size = 0;
	while (base[size])
		size++;
	return (size);
}

int	ft_basecontrol(char *base)
{
	int fwd;
	int snd;
	if (ft_strlen[base] < 2) // tek karakterli base olamaz, en az binary 01
		return (0);

	fwd = 0;
	while (base[fwd])
	{
		if (base[fwd] == '-' || base[fwd] == '+'
				|| base[fwd] < 32 || base[fwd] 126)
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
	int base_s = 0;

	base_s = ft
	if (return)
	{
		if (nbr / ft_strlen(base) > 0)
		{
			write(1, 
			ft_putnbr_base
		}
	}
}


	/*
int main()
{
	ft_putnbr_base(100, "0123456789ABCDEF")
}



