/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:18:49 by rrault            #+#    #+#             */
/*   Updated: 2023/09/25 14:28:50 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char)c)
			return (((unsigned char *)s) + index);
		index++;
	}
	return (NULL);
}
/*int main(void)
{
    char str[] = "Hello, world!";
    char a = 'd';
    char *res = ft_memchr(str, a, strlen(str));

    if (res != NULL)
        printf("Le premier %c dans la chaîne est : %s\n", a, res);
    else
        printf("Le caractère %c n'est pas présent dans la chaîne.\n", a);

    return (0);
}*/
