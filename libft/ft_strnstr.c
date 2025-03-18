/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:23:37 by azahid            #+#    #+#             */
/*   Updated: 2024/11/03 22:02:08 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	int	i;
	int	j;
	int	holder;

	i = 0;
	if (*tofind == '\0')
		return ((char *)str);
	if (tofind == str)
		return ((char *)str);
	while (str[i] && len)
	{
		j = 0;
		holder = len;
		while (tofind[j] && str[i] && holder-- && str[i + j] == tofind[j])
			j++;
		if (!tofind[j])
			return ((char *)str + i);
		i++;
		len--;
	}
	return (NULL);
}
