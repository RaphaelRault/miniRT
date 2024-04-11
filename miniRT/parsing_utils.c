/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:39:27 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 17:01:56 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_exvar	*ft_init_pd2(void)
{
	t_exvar	*var;

	var = malloc(sizeof(t_exvar));
	var->width = 0;
	var->height = 0;
	var->first_cam = NULL;
	var->background_color = (t_color){0.0, 0.0, 0.0};
	var->memory = 0;
	var->sepia = 0;
	var->ambient = (t_color){-1.0, -1.0, -1.0};
	return (var);
}

t_parsed_data	*ft_init_pd(t_exvar *var)
{
	t_parsed_data	*ret;

	ret = ft_malloc_save(sizeof(t_parsed_data), var);
	ret->cameras = 0;
	ret->lights = 0;
	ret->objects = 0;
	return (ret);
}

double	ft_stof(char *line, t_exvar *var)
{
	char	**temp;

	temp = ft_split(line, ".", var);
	if (!temp[1])
	{
		if (!ft_isdigit(temp[0]))
			ft_exit(0, "Incorrect float/int value!", var);
		return ((double)(ft_atoi(temp[0])));
	}
	if (!ft_isdigit(temp[0]) || !ft_isdigit(temp[1]))
		ft_exit(0, "Incorrect float/int value!", var);
	return ((double)ft_atoi(temp[0]) + ((double)ft_atoi(temp[1]) / pow(10,
				ft_strlen(temp[1]))));
}

t_color	ft_stoc(char *line, t_exvar *var)
{
	char	**temp;
	t_color	ret;

	temp = ft_split(line, ",", var);
	if (!temp[0] || !temp[1] || !temp[2])
		ft_exit(0, "Incorrect color description!", var);
	ret.r = ft_stof(temp[0], var);
	ret.g = ft_stof(temp[1], var);
	ret.b = ft_stof(temp[2], var);
	if (ret.r < 0 || ret.g < 0 || ret.b < 0 || ret.r > 255
		|| ret.g > 255 || ret.b > 255)
		ft_exit(0, "Color values can't be negative or more than 255.", var);
	return (ret);
}

t_point	ft_stop(char *line, t_exvar *var)
{
	char	**temp;

	temp = ft_split(line, ",", var);
	if (!temp[0] || !temp[1] || !temp[2])
		ft_exit(0, "Incorrect point description!", var);
	return ((t_point){ft_stof(temp[0], var), ft_stof(temp[1], var),
		ft_stof(temp[2], var)});
}
