/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:08:36 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 17:06:12 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ft_strnew(int size, t_exvar *var)
{
	return ((char *)ft_memalloc(sizeof(char) * (size + 1), var));
}

void	*ft_memalloc(int size, t_exvar *var)
{
	void	*ptr;
	char	*tmp;

	ptr = ft_malloc_save(size, var);
	tmp = ptr;
	while (size--)
		*tmp++ = '\0';
	return (ptr);
}
