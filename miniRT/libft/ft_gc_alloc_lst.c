/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_alloc_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:56:17 by rrault            #+#    #+#             */
/*   Updated: 2023/12/18 15:02:43 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_add_back(t_alloc_ptr *lst, t_alloc_ptr *new)
{
	t_alloc_ptr	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
	}
	tmp->next = new;
}

/*	This function defines a new node. */
t_alloc_ptr	*new_node(size_t size, char *name)
{
	t_alloc_ptr	*lst;

	lst = malloc(sizeof(t_alloc_ptr));
	if (!lst)
		return (NULL);
	lst->next = NULL;
	lst->size = size;
	lst->name = name;
	lst->addr = malloc(size);
	return (lst);
}

/*	This function free a node in the list. */
void	free_elem(t_alloc_ptr *element)
{
	if (element)
	{
		free(element->addr);
		free(element);
	}
}

/*	This function frees and remove the address of the given node in the
	list. */
t_alloc_ptr	*remove_address(int index, t_alloc_ptr *lst)
{
	t_alloc_ptr	*new_list;
	t_alloc_ptr	*past;

	if (!index)
	{
		new_list = lst->next;
		free_elem(lst);
		return (new_list);
	}
	new_list = lst;
	while (index)
	{
		past = lst;
		lst = lst->next;
		index--;
	}
	past->next = lst->next;
	free_elem(lst);
	return (new_list);
}

/*	This function display a list of every node within the garbage collector. */
void	print_address(void)
{
	int			i;
	t_alloc_ptr	*lst;

	i = 0;
	lst = addr_save(NULL, 1);
	printf("\tGarbage Collector Address:\n");
	printf("------------------------\n\n");
	printf("\033[1m[Index]\033[0m\t->\t\033[32m[Address]\033[34m\t\t[Name]\
		\033[0m\t->\t[Size]\n");
	while (lst)
	{
		printf("\033[1m[%d]\033[0m\t->\t\033[32m[%p]\033[34m\t[%s]\
			\033[0m->[%ld]\n",
			i++,
			lst->addr,
			lst->name,
			lst->size);
		lst = lst->next;
	}
	printf("------------------------\n");
}
