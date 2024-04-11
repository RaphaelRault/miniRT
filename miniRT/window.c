/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:12:13 by rrault            #+#    #+#             */
/*   Updated: 2024/02/26 11:05:45 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_exit(t_mlxvars *vars, char *msg, t_exvar *var)
{
	int	ret;

	ret = 0;
	if (msg)
		printf("Error\n%s\n", msg);
	if (vars)
	{
		if (vars->img.img)
			mlx_destroy_image(vars->mlx, vars->img.img);
		if (vars->win)
		{
			mlx_clear_window(vars->mlx, vars->win);
			mlx_destroy_window(vars->mlx, vars->win);
			mlx_destroy_display(vars->mlx);
			free(vars->mlx);
		}
	}
	if (var)
		ft_free(var);
	exit(1);
	return (ret);
}

void	ft_putpixel(t_mlxdata *data, t_vector2 vec, t_color color, t_exvar *var)
{
	char	*dst;

	vec.x = var->width / 2 + vec.x;
	vec.y = var->height / 2 - vec.y - 1;
	dst = data->addr + (vec.y * data->line_len + vec.x * (data->bbp / 8));
	*(unsigned int *)dst = ft_create_trgb(255, color, var);
}

void	ft_fill_image(t_mlxdata *img, t_parsed_data *data, t_exvar *var)
{
	t_ray		ray;
	t_color		color;
	t_camera	*camera;
	t_vector2	vec;

	vec.x = -var->width / 2;
	vec.y = -var->height / 2;
	camera = (t_camera *)data->cameras->node;
	while (vec.x < var->width / 2)
	{
		vec.y = -var->height / 2;
		while (vec.y < var->height / 2)
		{
			ray = ft_rotate(vec.x, vec.y, camera, var);
			color = ft_trace_ray((t_trpar){ray,
					data->objects, data->lights, 1.0, __DBL_MAX__,
					R_DEPTH}, var);
			ft_putpixel(img, vec, color, var);
			vec.y++;
		}
		vec.x++;
	}
}

void	ft_draw(t_mlxvars *vars, t_exvar *var)
{
	ft_fill_image(&vars->img, vars->data, var);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
