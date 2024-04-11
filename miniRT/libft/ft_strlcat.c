/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:33:37 by rrault            #+#    #+#             */
/*   Updated: 2023/04/13 11:39:33 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_strlen.c"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ld;
	size_t	i;

	ld = ft_strlen(dst);
	if (ld > size)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && ld + 1 < size)
		dst[ld++] = src[i++];
	dst[ld] = '\0';
	return (ld + ft_strlen(&src[i]));
}
/*
int    main(void)
{
    char    dst[50] = "Hello ";
    char    *src = "world!";
    size_t size = sizeof(dst);

    printf("Avant strlcat : dst = %s, src = %s\n", dst, src);
    size_t len = ft_strlcat(dst, src, size);
    printf("Apres strlcat : dst = %s, src = %s, len = %zu\n", dst, src, len);
    return (0);
}*/
