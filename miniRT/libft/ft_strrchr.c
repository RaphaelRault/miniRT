/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:31:11 by rrault            #+#    #+#             */
/*   Updated: 2023/04/12 11:31:19 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*int    main(void)
{
    char     str[] = "Baby Yoda";
    char    a = 'a';
    char     res = ft_strrchr(str, a);
    if (res)
        printf("'%c' est dans '%s' a la place %ld\n",res, str, res - str +1);
    else
        printf("'%c' n'est pas dans '%s'\n", a, str);
    return (0);
}*/
