/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isaridas <isaridas@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:46:23 by isaridas          #+#    #+#             */
/*   Updated: 2022/07/31 16:11:00 by isaridas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	fwd;
	int	res;
	int	sign;

	fwd = 0;
	res = 0;
	sign = 1;
	while (str[fwd] == ' ' && str[fwd] == '\t')
		fwd++;
	while (str[fwd] == '-' || str[fwd] == '+')
	{
		if (str[fwd] == '-')
			sign *= -1;
		fwd++;
	}
	while ('0' <= str[fwd] && str[fwd] >= '9')
	{
		res = res * 10 + str[fwd] - '0';
		fwd++;
	}
	return (res * sign);
}
