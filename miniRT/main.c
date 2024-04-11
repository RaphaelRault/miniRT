/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrault <rrault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:21:55 by rrault            #+#    #+#             */
/*   Updated: 2024/04/08 15:46:29 by rrault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_check_resolution(t_mlxvars *vars, t_exvar *var)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(vars->mlx, &sizex, &sizey);
	if (var->width > sizex)
	{
		printf("Too large width. Setting your display's maximum\n");
		var->width = sizex;
	}
	if (var->height > sizey)
	{
		printf("Too large height. Setting your display's maximum\n");
		var->height = sizey;
	}
}

int	main(int argc, char *argv[])
{
	t_mlxvars	vars;
	t_exvar		*var;

	var = ft_init_pd2();
	if (argc != 2)
		ft_exit(0, "Usage: ./miniRT <.rt file> [--save].", var);
	vars.data = ft_parser(argc, argv, var);
	var->first_cam = vars.data->cameras;
	vars.mlx = mlx_init();
	ft_check_resolution(&vars, var);
	mlx_do_key_autorepeatoff(vars.mlx);
	vars.win = mlx_new_window(vars.mlx, var->width, var->height, "miniRT");
	vars.img.img = mlx_new_image(vars.mlx, var->width, var->height);
	vars.img.addr = mlx_get_data_addr(vars.img.img,
			&vars.img.bbp, &vars.img.line_len, &vars.img.endian);
	vars.test = var;
	mlx_key_hook(vars.win, ft_key_pressed, &vars);
	mlx_expose_hook(vars.win, ft_expose, &vars);
	mlx_hook(vars.win, 33, 0L, ft_red_cross, &vars);
	ft_draw(&vars, var);
	mlx_loop(vars.mlx);
}
