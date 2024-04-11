/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:45:06 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 17:15:22 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_open_map(char *file, t_exvar *var)
{
	int	ret;

	if (file[ft_strlen(file) - 2] != 'r'
		&& file[ft_strlen(file) - 1] != 't')
		ft_exit(0, "The file is not a .rt", var);
	ret = open(file, O_RDONLY);
	return (ret);
}

t_point	ft_reflect_ray(t_point r, t_point n)
{
	return (vec_substract(vec_mul(2.0 * vec_point(r, n), n), r));
}

double	ft_vec_length(t_point a)
{
	return (sqrtf(vec_point(a, a)));
}

double	ft_modv(double vx, double vy, double vz)
{
	return (sqrtf(vx * vx + vy * vy + vz * vz));
}

t_point	ft_vec_cross(t_point a, t_point b)
{
	t_point	ret;

	ret.x = a.y * b.z - a.z * b.y;
	ret.y = a.z * b.x - a.x * b.z;
	ret.z = a.x * b.y - a.y * b.x;
	return (ret);
}
