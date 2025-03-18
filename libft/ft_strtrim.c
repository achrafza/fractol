/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:49:29 by azahid            #+#    #+#             */
/*   Updated: 2024/11/03 23:51:51 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	int			len;
	char		*str;

	start = s1;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	end = start + len - 1;
	while (*start && ft_isset(set, *start))
	{
		len--;
		start++;
	}
	while (end >= start && ft_isset(set, *end))
	{
		len--;
		end--;
	}
	str = ft_substr(s1, -(int)(s1 - start), len);
	return (str);
}
