/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:49:36 by azahid            #+#    #+#             */
/*   Updated: 2024/11/05 19:04:26 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	of(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

static int	ft_isspace(char c)
{
	return (c == '\t' || c == ' ' || c == '\v' || c == '\n'
		|| c == '\f' || c == '\r');
}

int	ft_atoi(const char	*str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (num > ((9223372036854775807 - (*str - '0')) / 10))
			return (of(sign));
		num = num * 10 + (*(str++) - '0');
	}
	return (num * sign);
}
