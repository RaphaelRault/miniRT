/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:38:37 by rrault            #+#    #+#             */
/*   Updated: 2023/04/17 10:38:42 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int,
	char*))
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
	s[i] = '\0';
}
/*
void    ft_f(unsigned int c, char *s)
{
    *s = *s + c;
}

int    main(void)
{
    char    str[] = "245";
    printf("Avant %s\n", str);
    ft_striteri(str, ft_f);
    printf("Apres %s\n", str);
    return (0);
}*/
