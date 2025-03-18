/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:29:27 by azahid            #+#    #+#             */
/*   Updated: 2025/02/05 16:48:08 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		strlen;

	if (!s1 && s2)
		return ((char *)s2);
	else if (s1 && !s2)
		return ((char *)s1);
	else if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	strlen = ft_strlcpy(str, s1, len1 + 1);
	strlen = ft_strlcat(str, s2, len2 + len1 + 1);
	return (str);
}
