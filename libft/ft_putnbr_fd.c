/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 00:52:37 by azahid            #+#    #+#             */
/*   Updated: 2024/11/06 01:19:29 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (n < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}
