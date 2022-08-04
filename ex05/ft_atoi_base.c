/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:04:20 by isaridas          #+#    #+#             */
/*   Updated: 2022/08/01 15:53:46 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int	ft_str_base_chk(char *str, char *base, unsigned int fwd)
{
	unsigned int	control;
	unsigned int	i;

	control = 0;
	i = 0;
	while (str[fwd])
	{
		while (base[i])
		{
			if (str[fwd] == base[i])
			{
				control = 1;
				break;
			}
			i++;
		}
		if (!control)
		{
			return (fwd);
		}
		fwd++;
		control = 0;
	}
	return (fwd);
}

int	ft_pwr(int base, int exp)
{
	if (exp == 0)
		return (1);
	int	result;

	result = 1;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
}

int	ft_pass_empty_char(char *str, int fwd, int *sign)
{
	while (str[fwd] == ' ' || str[fwd] == '\t')
		fwd++;
	while (str[fwd] == '-' || str[fwd] == '+')
	{
		if (str[fwd] == '-')
			*sign *= -1;
		fwd++;
	}
	return (fwd);
}

void	ft_cal_exp(int fwd, int last, unsigned int *exp)
{
	while (fwd < last)
	{
		(*exp)++;
		fwd++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	fwd;
	unsigned int	exp;
	unsigned int	last;
	int	sign;
	int	res;

	fwd = 0;
	sign = 1;
	res = 0;
	exp = 0;
	if (ft_basecontrol(base))
	{
		fwd = ft_pass_empty_char(str, fwd, &sign);
		last = ft_str_base_chk(str, base, fwd);
		ft_cal_exp(fwd, last, &exp);
		while (fwd < last)
		{
			res += (str[fwd] - '0') * ft_pwr(ft_strlen(base), exp - 1);
			exp--;
			fwd++;
		}
	}
	return (sign * res);
}

int main(void)
{
	printf("%d\n",ft_atoi_base(" ---+--+1234ab567", "0123456789ABCDEF"));
}
