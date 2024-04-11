/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:52:50 by rrault            #+#    #+#             */
/*   Updated: 2023/04/11 14:53:04 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>

int    main(void)
{
    char c = '.';
    if (ft_isascii(c))
        printf("%c est alphanumerique\n", c);
    else
        printf("%c n'est pas alphanumerique\n", c);
    return (0);
}*/
