/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:46:16 by azahid            #+#    #+#             */
/*   Updated: 2024/11/06 03:37:23 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*str_;

	str = (unsigned char *)src;
	str_ = (unsigned char *)dst;
	if (src < dst)
	{
		while (len)
		{
			str_[len - 1] = str[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
