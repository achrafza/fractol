/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:11:19 by azahid            #+#    #+#             */
/*   Updated: 2024/11/03 22:11:00 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen((char *)s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = 0;
	return (str);
}
