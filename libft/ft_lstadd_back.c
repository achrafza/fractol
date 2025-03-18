/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:07:12 by azahid            #+#    #+#             */
/*   Updated: 2024/11/06 15:33:48 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst && new)
	{
		tmp = ft_lstlast(*lst);
		if (!tmp)
		{
			new->next = NULL;
			*lst = new;
			return ;
		}
		tmp->next = new;
	}
}
