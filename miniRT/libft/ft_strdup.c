/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:29:28 by rrault            #+#    #+#             */
/*   Updated: 2023/04/14 14:36:29 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	*src = "Hello World";
	char	*dest;

	dest = ft_strdup(src);
	if (dest == NULL)
	{
		printf("Erreur d'allocation mémoire\n");
		exit(1);
	}
	printf("Chaine source : %s\n", src);
	printf("Chaine copiée : %s\n", dest);
	free(dest);
	return (0);
}*/
