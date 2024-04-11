/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:58:57 by rrault            #+#    #+#             */
/*   Updated: 2023/04/11 14:59:02 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*#include <stdio.h>

int    main(void)
{
    char c = '.';
    if (ft_isprint(c))
        printf("%c est alphanumerique\n", c);
    else
        printf("%c n'est pas alphanumerique\n", c);
    return (0);
}*/
