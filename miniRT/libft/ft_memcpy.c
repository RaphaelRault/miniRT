/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:42:53 by rrault            #+#    #+#             */
/*   Updated: 2023/04/12 13:42:56 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*#include <stdio.h>
#include <stdlib.h>

int    main(void)
{
    char src[] = "Hello world!";
    char *dest[sizeof(src)];

    printf("Avant memcpy: \nsrc : %s dest : %s\n", src, dest);
    ft_memcpy(dest, src, sizeof(src));
    printf("Apres memcpy: \nsrc : %s dest : %s\n", src, dest);
    return (0);
}*/
