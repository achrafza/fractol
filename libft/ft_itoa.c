/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:37:52 by azahid            #+#    #+#             */
/*   Updated: 2024/11/05 19:31:29 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*fill(long x, char *p, int len)
{
	int		i;

	i = len;
	p[len] = '\0';
	if (x < 0)
	{
		p[0] = '-';
		len--;
		x *= -1;
	}
	while (len)
	{
		p[i - 1] = (x % 10) + '0';
		x /= 10;
		len--;
		i--;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;
	long	x;

	x = n;
	len = num_len(x);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	return (fill(x, p, len));
}
