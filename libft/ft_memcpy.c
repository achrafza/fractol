/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:40:27 by azahid            #+#    #+#             */
/*   Updated: 2024/11/06 16:52:57 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str_;

	if (!dst && !src)
		return (NULL);
	str = (unsigned char *)src;
	str_ = (unsigned char *)dst;
	if (src == dst)
		return ((void *)(src));
	while (n--)
	{
		*str_ = *str;
		str++;
		str_++;
	}
	return (dst);
}
