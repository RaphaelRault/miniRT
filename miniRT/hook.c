/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:27:25 by rrault            #+#    #+#             */
/*   Updated: 2024/02/23 17:01:20 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_red_cross(t_mlxvars *vars)
{
	ft_exit(vars, 0, vars->test);
	return (0);
}

int	ft_expose(t_mlxvars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (1);
}

int	ft_key_pressed(int keycode, t_mlxvars *vars)
{
	if (keycode == KEYCODE_ESC)
		ft_exit(vars, 0, vars->test);
	if (keycode == KEYCODE_Q)
		ft_switch_cam(vars, vars->test);
	if (keycode == KEYCODE_W || keycode == KEYCODE_A || keycode == KEYCODE_S
		|| keycode == KEYCODE_D || keycode == KEYCODE_SHIFT
		|| keycode == KEYCODE_CTRL)
		ft_translate_cam(keycode, vars, vars->test);
	if (keycode == KEYCODE_UP || keycode == KEYCODE_LEFT
		|| keycode == KEYCODE_DOWN || keycode == KEYCODE_RIGHT
		|| keycode == KEYCODE_RSHIFT)
		ft_rotate_cam(keycode, vars, vars->test);
	if (keycode == KEYCODE_E)
		ft_restore_cam(vars, vars->test);
	return (0);
}
