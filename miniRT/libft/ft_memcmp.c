/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:42:02 by rrault            #+#    #+#             */
/*   Updated: 2023/04/14 13:47:35 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr1;

	if (n == 0)
		return (0);
	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	while ((*ptr == *ptr1) && n - 1 > 0)
	{
		ptr++;
		ptr1++;
		n--;
	}
	return ((int)(*ptr - *ptr1));
}
/*
int main(void)
{
    char str1[] = "Hello World";
    char str2[] = "Hella world";
    int n = 6;

    int result = ft_memcmp(str1, str2, n);

    if (result > 0)
        printf("Les %d caractères de str1 sont supérieurs à str2.\n", n);
    else if (result < 0)
        printf("Les %d caractères de str2 sont supérieurs à str1.\n", n);
    else
        printf("Les %d caractères de str1 et str2 sont identiques.\n", n);

    return 0;
}*/
