/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:50 by aramier           #+#    #+#             */
/*   Updated: 2024/02/26 10:39:33 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	vec_substract(t_point a, t_point b)
{
	t_point	ret;

	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return (ret);
}

double	vec_point(t_point a, t_point b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_point	vec_add(t_point a, t_point b)
{
	t_point	ret;

	ret.x = a.x + b.x;
	ret.y = a.y + b.y;
	ret.z = a.z + b.z;
	return (ret);
}

t_point	vec_norm(t_point vec)
{
	t_point	ret;
	double	mod_v;

	mod_v = ft_modv(vec.x, vec.y, vec.z);
	ret.x = vec.x / mod_v;
	ret.y = vec.y / mod_v;
	ret.z = vec.z / mod_v;
	return (ret);
}

t_point	vec_mul(double k, t_point a)
{
	t_point	ret;

	ret.x = a.x * k;
	ret.y = a.y * k;
	ret.z = a.z * k;
	return (ret);
}
