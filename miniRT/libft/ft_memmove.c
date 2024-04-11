/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 09:33:16 by rrault            #+#    #+#             */
/*   Updated: 2023/04/14 09:41:29 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dest;
	i = -1;
	if (!s && !d)
		return (NULL);
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		while (++i < len)
			d[i] = s[i];
	}
	return (dest);
}
/*
int main(void)
{
	char	src[] = "Hello";
	char	dest[30] = "000000000000000";
	printf("%s", (char *)ft_memmove(dest, src, 5));
	for (int i = 0;i < 35; i++)
	{
		printf("%c", dest[i]);
		if (dest[i] == 0)
			printf("!");
	}
	printf(".....");
}*/
