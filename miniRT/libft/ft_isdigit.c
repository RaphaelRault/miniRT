/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:54:45 by rrault            #+#    #+#             */
/*   Updated: 2024/02/02 10:03:20 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char *str)
{
	char	*ptr;

	ptr = str;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr)
	{
		if (!(*ptr >= '0' && *ptr <= '9'))
			return (0);
		ptr++;
	}
	return (1);
}

/*#include <stdio.h>

int    main(void)
{
    char c = '.';
    if (ft_isdigit(c))
        printf("%c est alphanumerique\n", c);
    else
        printf("%c n'est pas alphanumerique\n", c);
    return (0);
}*/
