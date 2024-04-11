/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:47:37 by rrault            #+#    #+#             */
/*   Updated: 2024/02/26 14:12:23 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_parsed_data	*ft_parse_processor(char *line, t_parsed_data *data,
		t_exvar *var)
{
	if (line[0] == 'R')
		ft_parse_res(line, var);
	else if (line[0] == 'A')
		data->lights = ft_ladd(data->lights, ft_lnew(ft_parse_amb(line, var),
					var));
	else if (line[0] == 'c' && line[1] == ' ')
		data->cameras = ft_ladd(data->cameras, ft_lnew(ft_parse_camera(line,
						var), var));
	else if (line[0] == 'l' && line[1] == ' ')
		data->lights = ft_ladd(data->lights, ft_lnew(ft_parse_light(line, var),
					var));
	else if (line[0] == 's' && line[1] == 'p' && line[2] == ' ')
		data->objects = ft_ladd(data->objects, ft_lnew(ft_parse_sphere(line,
						var), var));
	else if (line[0] == 'p' && line[1] == 'l' && line[2] == ' ')
		data->objects = ft_ladd(data->objects, ft_lnew(ft_parse_plane(line,
						var), var));
	else if (line[0] == 'c' && line[1] == 'y' && line[2] == ' ')
		data->objects = ft_ladd(data->objects, ft_parse_cylinder(line, var));
	return (data);
}
