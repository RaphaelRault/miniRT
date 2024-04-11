/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:54:11 by rrault            #+#    #+#             */
/*   Updated: 2024/02/22 17:25:51 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int    main()
{
    char str[] = "ASDFGHJK";
    int u = 0;
    while (str[u])
        u++;
    printf("Avant bzero : %s\n", str);
    ft_bzero(str, 4);
    printf("Apres bzero : %s", str);

    int i = 0;
    while (i < u)
    {
        printf("%c", str[i]);
        i++;
    }
    return (0);
}*/
