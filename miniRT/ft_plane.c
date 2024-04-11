/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:42:18 by aramier           #+#    #+#             */
/*   Updated: 2024/02/23 17:05:05 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_solutions	ft_intersect_plane(void *data, t_ray ray)
{
	t_plane		*plane;
	t_solutions	ret;
	double		normdir;
	double		t;

	ret.t1 = __DBL_MAX__;
	ret.t2 = __DBL_MAX__;
	plane = data;
	normdir = vec_point(plane->norm, ray.direction);
	if (fabs(normdir) > 0)
	{
		t = vec_point(vec_substract(plane->axe_pos, ray.origin), plane->norm)
			/ normdir;
		if (t >= 0)
			ret.t1 = t;
	}
	return (ret);
}

t_point	ft_plane_normal(void *data, t_point intersection, t_ray ray)
{
	t_plane	*plane;

	plane = data;
	(void)intersection;
	return (ft_rotate_normal(ray, plane->norm, intersection));
}

t_obj	*ft_create_plane(t_pl_params params, t_exvar *var)
{
	t_plane		*plane;
	t_obj		*obj;

	plane = ft_malloc_save(sizeof(t_plane), var);
	obj = ft_malloc_save(sizeof(t_obj), var);
	plane->axe_pos = params.axe_pos;
	plane->norm = vec_norm(params.norm);
	obj->data = plane;
	obj->type = PLANE;
	obj->ft_intersect = ft_intersect_plane;
	obj->ft_get_norm = ft_plane_normal;
	obj->color = params.color;
	obj->refl = params.reflection;
	obj->spec = params.spec;
	return (obj);
}
