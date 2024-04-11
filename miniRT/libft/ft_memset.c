/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:28:43 by rrault            #+#    #+#             */
/*   Updated: 2023/04/12 15:33:28 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int    main(void)
{
    char    str[20] = "Hello world!";

    printf("Avant memset: %s\n", str);
    ft_memset(str + 6, 'x', 5);
    printf("Apres memset: %s\n", str);
    return (0);
}*/
