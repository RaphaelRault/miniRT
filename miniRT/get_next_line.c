/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:07:59 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 17:06:24 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_appendremainder(char **remainder, char *buf, t_exvar *var)
{
	char	*ptr;

	ptr = ft_strnew(ft_strlen(*remainder) + BUFFER_SIZE, var);
	ft_memcpy(ptr, *remainder, ft_strlen(*remainder));
	ft_memcpy(ptr + ft_strlen(*remainder), buf, ft_strlen(buf));
	*remainder = ptr;
	return (0);
}

int	ft_appendline(char **line, char **remainder, t_exvar *var)
{
	char	*new;
	char	*tmp;

	tmp = ft_strchr(*remainder, '\n');
	*line = ft_strnew(tmp - *remainder, var);
	new = ft_strnew(ft_strlen(*remainder), var);
	ft_memcpy(*line, *remainder, (tmp - *remainder));
	*tmp = 0;
	tmp++;
	ft_memcpy(new, tmp, ft_strlen(tmp));
	*remainder = new;
	return (1);
}

int	ft_appendline2(char **line, char **remainder, t_exvar *var)
{
	*line = ft_strnew(ft_strlen(*remainder), var);
	ft_memcpy(*line, *remainder, ft_strlen(*remainder));
	*remainder = 0;
	return (0);
}

int	get_next_line(int fd, char **line, t_exvar *var)
{
	static char	*remainder;
	char		*buf;
	int			readret;

	if (!remainder)
		remainder = ft_strnew(0, var);
	buf = ft_strnew(BUFFER_SIZE, var);
	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, NULL, 0)) < 0
		|| !remainder || !buf || !line)
		return (-1);
	readret = read(fd, buf, BUFFER_SIZE);
	while (readret >= 0)
	{
		buf[readret] = 0;
		ft_appendremainder(&remainder, buf, var);
		if (ft_strchr(remainder, '\n'))
			return (ft_appendline(line, &remainder, var));
		if (readret < BUFFER_SIZE)
			return (ft_appendline2(line, &remainder, var));
		readret = read(fd, buf, BUFFER_SIZE);
	}
	return (-1);
}
