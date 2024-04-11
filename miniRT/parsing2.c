/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:57:32 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 17:10:56 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lst	*ft_cylinder_caps(t_obj *obj, t_cy_params params, t_exvar *var)
{
	t_lst		*ret;
	t_obj		*top_cap;
	t_obj		*bottom_cap;

	top_cap = ft_create_disc((t_ds_params){
			params.axe_pos, vec_mul(-1, params.orient),
			params.color, params.diam / 2.0,
			params.reflection, params.spec}, var);
	bottom_cap = ft_create_disc((t_ds_params){
			vec_add(params.axe_pos, vec_mul(params.height,
					params.orient)), params.orient, params.color,
			params.diam / 2.0, params.reflection, params.spec},
			var);
	ret = ft_lnew(obj, var);
	ret->next = ft_lnew(top_cap, var);
	((t_lst *)ret->next)->next = ft_lnew(bottom_cap, var);
	return (ret);
}

t_lst	*ft_parse_cylinder(char *line, t_exvar *var)
{
	char		**words;
	t_cy_params	params;
	int			caps;

	words = ft_split(line, ISSPACE, var);
	if (!words[1] || !words[2] || !words[3] || !words[4] || !words[5])
		ft_exit(0, "Required parameter missing in cylinder!", var);
	params.axe_pos = ft_stop(words[1], var);
	params.orient = ft_stop(words[2], var);
	params.diam = ft_stof(words[3], var);
	params.height = ft_stof(words[4], var);
	params.color = ft_stoc(words[5], var);
	params.reflection = 0.1;
	params.spec = 100;
	caps = 0;
	if (words[6])
		caps = ft_stof(words[6], var);
	if (words[6] && words[7])
		params.reflection = ft_stof(words[7], var);
	if (words[6] && words[7] && words[8])
		params.spec = ft_stof(words[8], var);
	if (caps)
		return (ft_cylinder_caps(ft_create_cylinder(params, var), params, var));
	return (ft_lnew(ft_create_cylinder(params, var), var));
}

t_obj	*ft_parse_plane(char *line, t_exvar *var)
{
	char		**words;
	t_obj		*ret;
	t_pl_params	params;

	words = ft_split(line, ISSPACE, var);
	if (!words[1] || !words[2] || !words[3])
		ft_exit(0, "Required parameter missing in plane!", var);
	params.axe_pos = ft_stop(words[1], var);
	params.norm = ft_stop(words[2], var);
	params.color = ft_stoc(words[3], var);
	params.reflection = 0.1;
	params.spec = 100;
	if (words[4])
		params.reflection = ft_stof(words[4], var);
	if (words[4] && words[5])
		params.spec = ft_stof(words[5], var);
	ret = ft_create_plane(params, var);
	return (ret);
}

t_obj	*ft_parse_sphere(char *line, t_exvar *var)
{
	char		**words;
	t_obj		*ret;
	t_sp_params	params;

	words = ft_split(line, ISSPACE, var);
	if (!words[1] || !words[2] || !words[3])
		ft_exit(0, "Required parameter missing in sphere!", var);
	params.center = ft_stop(words[1], var);
	params.radius = ft_stof(words[2], var);
	params.color = ft_stoc(words[3], var);
	params.reflection = 0.1;
	params.spec = 100;
	if (words[4])
		params.reflection = ft_stof(words[4], var);
	if (words[4] && words[5])
		params.spec = ft_stof(words[5], var);
	ret = ft_create_sphere(params, var);
	return (ret);
}
