/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:34:43 by rrault            #+#    #+#             */
/*   Updated: 2023/04/12 12:35:10 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}
/*
int    main(void)
{
    char    *str = "Baby Yoda";
    char    o = 'a';
    char    *a = ft_strchr(str, o);

    if (a)
        printf("%c est present dans "%s" a cette position %ld.\n", 
        o, str, a - str + 1);
    else
        printf("%c n'est present dans "%s".\n", o, str);
    return (0);
}*/
