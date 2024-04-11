/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:57:48 by rrault            #+#    #+#             */
/*   Updated: 2024/02/26 15:24:02 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_solutions	ft_intersect_sphere(void *data, t_ray ray)
{
	t_solutions	ret;
	t_sphere	*sphere;
	t_point		oc;
	double		discriminant;
	double		k[3];

	sphere = data;
	oc = vec_substract(ray.origin, sphere->center);
	k[0] = vec_point(ray.direction, ray.direction);
	k[1] = 2.0 * vec_point(oc, ray.direction);
	k[2] = vec_point(oc, oc) - sphere->radius * sphere->radius;
	discriminant = k[1] * k[1] - 4.0 * k[0] * k[2];
	if (discriminant < -0.0001)
	{
		ret.t1 = __DBL_MAX__;
		ret.t2 = __DBL_MAX__;
		return (ret);
	}
	ret.t1 = (-k[1] + sqrtf(discriminant)) / (2.0 * k[0]);
	ret.t2 = (-k[1] - sqrtf(discriminant)) / (2.0 * k[0]);
	return (ret);
}

t_point	ft_get_normal_sphere(void *data, t_point intersection, t_ray ray)
{
	t_sphere	*sphere;
	t_point		ret;

	sphere = data;
	ret = vec_substract(intersection, sphere->center);
	ret = vec_mul(1.0 / ft_vec_length(ret), ret);
	return (ft_rotate_normal(ray, ret, intersection));
}

t_obj	*ft_create_sphere(t_sp_params params, t_exvar *var)
{
	t_sphere	*sphere;
	t_obj		*obj;

	sphere = ft_malloc_save(sizeof(t_sphere), var);
	obj = ft_malloc_save(sizeof(t_obj), var);
	sphere->center = params.center;
	sphere->radius = params.radius;
	obj->data = sphere;
	obj->type = SPHERE;
	obj->ft_intersect = ft_intersect_sphere;
	obj->ft_get_norm = ft_get_normal_sphere;
	obj->color = params.color;
	obj->refl = params.reflection;
	obj->spec = params.spec;
	return (obj);
}
