/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:44:58 by aramier           #+#    #+#             */
/*   Updated: 2024/02/23 17:57:17 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_color_add(t_color a, t_color b)
{
	t_color	color;

	color.r = a.r + b.r;
	color.g = a.g + b.g;
	color.b = a.b + b.b;
	return (color);
}

int	ft_create_trgb(int t, t_color color, t_exvar *var)
{
	if (var->sepia)
	{
		color.r = (color.r * 0.393) + (color.g * 0.769) + (color.b * 0.189);
		color.g = (color.r * 0.349) + (color.g * 0.686) + (color.b * 0.168);
		color.b = (color.r * 0.272) + (color.g * 0.534) + (color.b * 0.131);
	}
	color.r = fmin(255, fmax(0, color.r));
	color.g = fmin(255, fmax(0, color.g));
	color.b = fmin(255, fmax(0, color.b));
	return (t << 24 | (int)color.r << 16 | (int)color.g << 8 | (int)color.b);
}

t_color	ft_color_multiply(double a, t_color color)
{
	t_color	ret;

	ret.r = color.r * a;
	ret.g = color.g * a;
	ret.b = color.b * a;
	return (ret);
}

t_color	ft_color_average(t_color a, t_color b)
{
	t_color		ret;

	ret.r = a.r * b.r / 255;
	ret.g = a.g * b.g / 255;
	ret.b = a.b * b.b / 255;
	return (ret);
}
