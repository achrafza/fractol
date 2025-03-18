/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:14:18 by azahid            #+#    #+#             */
/*   Updated: 2024/11/03 21:07:29 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			destlen;
	size_t			srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	destlen = ft_strlen(dest);
	if (size < destlen)
		return (size + srclen);
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (destlen + srclen);
}
