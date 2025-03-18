/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:48:23 by azahid            #+#    #+#             */
/*   Updated: 2024/11/03 02:51:26 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	char	*temp;

	temp = NULL;
	while (*s)
	{
		if (*s == (char)c)
			temp = s;
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (temp);
}
