/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:48:17 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 17:01:38 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lst	*ft_lnew(void *content, t_exvar *var)
{
	t_lst	*ret;

	ret = ft_malloc_save(sizeof(t_lst), var);
	if (!ret)
		return (0);
	if (!content)
		ret->node = 0;
	else
		ret->node = content;
	ret->next = 0;
	return (ret);
}

t_lst	*ft_ladd(t_lst *lst, t_lst *new)
{
	t_lst	*ret;
	t_lst	*cur;

	if (!lst)
	{
		lst = new;
		return (lst);
	}
	cur = lst;
	ret = lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (ret);
}
