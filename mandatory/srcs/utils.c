/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:34:22 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 05:38:40 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	normnumbers(int *i, int *sign, double *power, double *res)
{
	*i = 0;
	*sign = 1;
	*power = 1;
	*res = 0;
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	double	power;
	double	res;

	normnumbers(&i, &sign, &power, &res);
	while (str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (('0' <= str[i] && str[i] <= '9'))
		res = res * 10 + (str[i++] - '0');
	if (str[i] == '.' || str[i] == ',')
		i++;
	while (('0' <= str[i] && str[i] <= '9'))
	{
		power = power / 10;
		res = res + (str[i] - '0') * power;
		i++;
	}
	return (res * sign);
}

int	figureoutiter(int temp)
{
	int		r;
	int		g;
	int		b;
	double	t;

	t = (double)(((double)temp / MAXITER) * 11);
	r = (int)(sin(t * 5 + 3) * 127 + 128);
	g = (int)(sin(t * 5 + 2) * 127 + 128);
	b = (int)(sin(t * 5 + 5) * 127 + 128);
	return (255 << 24 | r << 16 | g << 8 | b);
}
