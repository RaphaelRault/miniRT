/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:12:35 by aramier           #+#    #+#             */
/*   Updated: 2024/02/23 17:04:56 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_solutions	ft_intersect_disc(void *data, t_ray ray)
{
	t_solutions	ret;
	t_disc		*disc;

	disc = data;
	ret = ft_intersect_plane((void *)disc->plane, ray);
	if (ret.t1 < __DBL_MAX__ && ft_vec_length(vec_substract(vec_add(ray.origin,
					vec_mul(ret.t1, ray.direction)),
				disc->axe_pos)) <= disc->ray)
		return (ret);
	return ((t_solutions){__DBL_MAX__, __DBL_MAX__});
}

t_point	ft_get_normal_disc(void *data, t_point intersection, t_ray ray)
{
	t_disc	*disc;

	disc = data;
	(void)intersection;
	return (ft_rotate_normal(ray, disc->norm, intersection));
}

t_obj	*ft_create_disc(t_ds_params params, t_exvar *var)
{
	t_disc		*disc;
	t_obj		*obj;

	disc = ft_malloc_save(sizeof(t_disc), var);
	disc->plane = ft_malloc_save(sizeof(t_plane), var);
	obj = ft_malloc_save(sizeof(t_obj), var);
	disc->axe_pos = params.axe_pos;
	disc->norm = vec_norm(params.norm);
	disc->ray = params.r;
	disc->plane->axe_pos = params.axe_pos;
	disc->plane->norm = vec_norm(params.norm);
	obj->data = disc;
	obj->type = DISC;
	obj->ft_intersect = ft_intersect_disc;
	obj->ft_get_norm = ft_get_normal_disc;
	obj->color = params.color;
	obj->refl = params.reflection;
	obj->spec = params.spec;
	return (obj);
}
