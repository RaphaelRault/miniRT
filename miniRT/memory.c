/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:49:16 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 19:08:30 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*ft_malloc_save(int size, t_exvar *var)
{
	void	*ret;
	t_lst	*cur;
	t_lst	*new;

	ret = malloc(size);
	if (!ret)
		ft_exit(0, "Malloc error o.o", var);
	ft_bzero(ret, size);
	new = malloc(sizeof(t_lst));
	if (!new)
		ft_exit(0, "Malloc error o.o", var);
	new->node = ret;
	new->next = 0;
	if (!var->memory)
	{
		var->memory = malloc(sizeof(t_lst));
		var->memory->node = malloc(1);
		var->memory->next = 0;
	}
	cur = var->memory;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (ret);
}

void	ft_free(t_exvar *var)
{
	t_lst	*cur;
	t_lst	*temp;

	cur = var->memory;
	while (cur)
	{
		temp = cur;
		cur = temp->next;
		free(temp->node);
		free(temp);
	}
	free(var);
}
