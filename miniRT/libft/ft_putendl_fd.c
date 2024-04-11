/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:27:45 by rrault            #+#    #+#             */
/*   Updated: 2023/04/17 10:32:13 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include "ft_putstr_fd.c"
//#include "ft_putchar_fd.c"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*int    main(void)
{
    char    *m = "Baby Yoda!";
    int    fd = STDOUT_FILENO;

    ft_putendl_fd(m, fd);
    return (0);
}*/
