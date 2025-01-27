/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:19:15 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 18:08:30 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_compute_lighting3(t_covars *vars, t_copar args)
{
	if (((t_light *)vars->cur->node)->ltype == POINT)
	{
		vars->light = vec_substract(((t_light *)vars->cur->node)->position,
				args.p);
		vars->t_max = 1.0;
	}
	else if (((t_light *)vars->cur->node)->ltype == DIRECTION)
		vars->light = ((t_light *)vars->cur->node)->position;
}

double	ft_compute_lighting2(t_covars vars, t_copar args)
{
	double	ret;
	t_point	normal;

	ret = 0;
	normal = args.obj->ft_get_norm(args.obj->data,
			args.p, args.ray);
	vars.n_l = vec_point(normal, vars.light);
	if (vars.n_l > 0)
		ret += ((t_light *)vars.cur->node)->intensity * vars.n_l
			/ (ft_vec_length(normal) * ft_vec_length(vars.light));
	if (args.obj->spec != -1)
	{
		vars.ray = ft_reflect_ray(vars.light, normal);
		vars.r_v = vec_point(vars.ray, args.view);
		if (vars.r_v > 0)
			ret += ((t_light *)vars.cur->node)->intensity * powf(vars.r_v
					/ (ft_vec_length(vars.ray) * ft_vec_length(args.view)),
					args.obj->spec);
	}
	return (ret);
}

void	ft_init_compute(t_covars *vars, t_copar args, t_exvar *var)
{
	vars->t_max = __DBL_MAX__;
	vars->cur = args.lights;
	vars->ret = var->ambient;
	vars->intensity = 0;
}

t_color	ft_compute_lighting(t_copar args, t_exvar *var, t_covars *vars)
{
	ft_init_compute(vars, args, var);
	while (vars->cur)
	{
		if (((t_light *)vars->cur->node)->ltype == AMBIENT)
			vars->intensity += ((t_light *)vars->cur->node)->intensity;
		else
		{
			ft_compute_lighting3(vars, args);
			if ((ft_closest((t_clpar){(t_ray){args.p, vars->light}, 0.1,
					vars->t_max, args.objects})).obj
				&& ((t_light *)vars->cur->node)->intensity > 0)
			{
				vars->cur = vars->cur->next;
				continue ;
			}
			vars->intensity += ft_compute_lighting2(*vars, args);
		}
		vars->ret = ft_color_add(vars->ret, ft_color_average(args.obj->color,
					ft_color_multiply(vars->intensity,
						((t_light *)vars->cur->node)->color)));
		vars->intensity = 0;
		vars->cur = vars->cur->next;
	}
	return (vars->ret);
}
