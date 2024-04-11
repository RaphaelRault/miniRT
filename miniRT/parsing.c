/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:12:17 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 17:01:59 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*ft_parse_light(char *line, t_exvar *var)
{
	char	**words;
	t_light	*ret;

	ret = ft_malloc_save(sizeof(t_light), var);
	words = ft_split(line, ISSPACE, var);
	if (!words[1] || !words[2] || !words[3])
		ft_exit(0, "Required parameter missing in light!", var);
	if (words[4])
		ret->ltype = DIRECTION;
	else
		ret->ltype = POINT;
	ret->position = ft_stop(words[1], var);
	ret->intensity = ft_stof(words[2], var);
	if (ret->intensity < 0 || ret->intensity > 1)
		ft_exit(0, "Incorrect light intensity is set.", var);
	ret->color = ft_stoc(words[3], var);
	return (ret);
}

t_camera	*ft_parse_camera(char *line, t_exvar *var)
{
	char		**words;
	t_camera	*ret;

	ret = ft_malloc_save(sizeof(t_camera), var);
	words = ft_split(line, ISSPACE, var);
	if (!words[1] || !words[2] || !words[3])
		ft_exit(0, "Required parameter missing in camera!", var);
	ret->pos = ft_stop(words[1], var);
	ret->rotation = ft_stop(words[2], var);
	if (ret->rotation.y != 0 && ret->rotation.x == 0 && ret->rotation.z == 0)
		ret->rotation.z = 0.001;
	ret->fov = ft_stof(words[3], var);
	if (ret->fov > 180 || ret->fov < 0)
		ft_exit(0, "Incorrect camera FOV.", var);
	if (ret->fov == 180)
		ret->fov = 179;
	ret->save_pos = ret->pos;
	ret->save_rotation = ret->rotation;
	return (ret);
}

t_light	*ft_parse_amb(char *line, t_exvar *var)
{
	char	**words;
	t_light	*ret;

	ret = ft_malloc_save(sizeof(t_light), var);
	words = ft_split(line, ISSPACE, var);
	if (!words[1] || !words[2])
		ft_exit(0, "Required parameter missing in ambient light!", var);
	ret->ltype = AMBIENT;
	ret->intensity = ft_stof(words[1], var);
	if (ret->intensity < 0.0 || ret->intensity > 1.0)
		ft_exit(0, "Incorrect intensity", var);
	ret->color = ft_stoc(words[2], var);
	if (var->ambient.r != -1)
		ft_exit(0, "Multiple ambient lights are set.", var);
	var->ambient = ft_color_multiply(ret->intensity, ret->color);
	return (ret);
}

void	ft_parse_res(char *line, t_exvar *var)
{
	char	**words;

	words = ft_split(line, ISSPACE, var);
	if (!words[1] || !words[2])
		ft_exit(0, "Required parameter missing in resolution!", var);
	if (var->width != 0 || var->height != 0)
		ft_exit(0, "Multiple resolutions are set.", var);
	var->width = (double)ft_stof(words[1], var);
	var->height = (double)ft_stof(words[2], var);
	if (var->width <= 0 || var->height <= 0)
		ft_exit(0, "Wrong resolution is set.", var);
}

t_parsed_data	*ft_parser(int argc, char *argv[], t_exvar *var)
{
	t_parsed_data	*ret;
	int				fd;
	char			*line;
	int				i;

	ret = ft_init_pd(var);
	if (argc >= 2)
	{
		fd = ft_open_map(argv[1], var);
		while (1)
		{
			i = get_next_line(fd, &line, var);
			if (i == 1)
				ret = ft_parse_processor(line, ret, var);
			else if (i == -1)
				ft_exit(0, "File reading error!", var);
			else if (i == 0)
			{
				ret = ft_parse_processor(line, ret, var);
				break ;
			}
		}
		close(fd);
	}
	return (ret);
}
