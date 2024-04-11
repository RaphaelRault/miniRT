/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:56:50 by rrault            #+#    #+#             */
/*   Updated: 2023/04/14 14:59:08 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}
/*
int main()
{
	int i = 0;
	int n = 6;
	int *ptr = calloc(n, sizeof(int));
    if (ptr == NULL) 
    {
        printf("Allocation failed\n");
        return 1;
    }
    while (i < n) 
    {
        printf("%d\n", ptr[i]);
        i++;
    }
    free(ptr);
    return 0;
}*/
