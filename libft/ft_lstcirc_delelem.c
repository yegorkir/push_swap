/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcirc_delelem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <mdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:28:43 by mdeanne           #+#    #+#             */
/*   Updated: 2019/06/27 17:29:14 by mdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcirc_delelem(t_list **cur, t_list *del_elem)
{
	t_list *prev;

	if (cur && *cur && del_elem)
	{
		*cur = (*cur)->next;
		while ((*cur)->next != del_elem)
			*cur = (*cur)->next;
		prev = *cur;
		*cur = (*cur)->next;
		prev->next = (*cur)->next;
		free((*cur)->content);
		(*cur)->next = NULL;
		if (*cur != prev)
		{
			free(*cur);
			*cur = prev->next;
		}
		else
			*cur = NULL;
		return (1);
	}
	return (0);
}
