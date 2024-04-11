/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:41:10 by rrault            #+#    #+#             */
/*   Updated: 2024/02/26 10:25:22 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_closest	ft_closest(t_clpar params)
{
	t_closest	ret;
	t_solutions	ir;
	t_lst		*cur;

	ret.t = __DBL_MAX__;
	ret.obj = 0;
	cur = params.objects;
	while (cur)
	{
		ir = ((t_obj *)cur->node)->ft_intersect(((t_obj *)cur->node)->data,
				params.ray);
		if (ir.t1 < ret.t && params.t_min < ir.t1 && ir.t1 < params.t_max)
		{
			ret.t = ir.t1;
			ret.obj = ((t_obj *)cur->node);
		}
		if (ir.t2 < ret.t && params.t_min < ir.t2 && ir.t2 < params.t_max)
		{
			ret.t = ir.t2;
			ret.obj = ((t_obj *)cur->node);
		}
		cur = cur->next;
	}
	return (ret);
}

t_color	ft_trace_ray(t_trpar args, t_exvar *var)
{
	t_closest	closest;
	t_point		re_ray;
	t_color		colors[2];
	t_covars	vars;

	closest = ft_closest((t_clpar){args.ray,
			args.t_min, args.t_max, args.objects});
	if (!closest.obj)
		return (var->background_color);
	closest.inter = vec_add(args.ray.origin,
			vec_mul(closest.t, args.ray.direction));
	colors[0] = ft_compute_lighting((t_copar){closest.inter, vec_mul(-1,
				args.ray.direction), closest.obj, args.objects, args.lights,
			args.ray}, var, &vars);
	if (closest.obj->refl <= 0 || args.r_depth <= 0)
		return (colors[0]);
	re_ray = ft_reflect_ray(vec_mul(-1, args.ray.direction),
			closest.obj->ft_get_norm(closest.obj->data,
				closest.inter, args.ray));
	colors[1] = ft_trace_ray((t_trpar){(t_ray){closest.inter, re_ray},
			args.objects, args.lights, 0.1, __DBL_MAX__, args.r_depth - 1},
			var);
	return (ft_color_add(ft_color_multiply(1.0 - closest.obj->refl, colors[0]),
			ft_color_multiply(closest.obj->refl, colors[1])));
}
