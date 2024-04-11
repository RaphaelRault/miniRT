/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramier <aramier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:58:12 by rrault            #+#    #+#             */
/*   Updated: 2024/02/26 15:30:42 by aramier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define M_PI 3.14159265358979323846
# define BUFFER_SIZE 1
# define KEYCODE_ESC 65307
# define KEYCODE_Q 113
# define KEYCODE_E 101
# define KEYCODE_W 119
# define KEYCODE_A 97
# define KEYCODE_S 115
# define KEYCODE_D 100
# define KEYCODE_SHIFT 65505
# define KEYCODE_RSHIFT 65506
# define KEYCODE_CTRL 65507
# define KEYCODE_UP 65362
# define KEYCODE_LEFT 65361
# define KEYCODE_DOWN 65364
# define KEYCODE_RIGHT 65363
# define R_DEPTH 10
# define ISSPACE " \t"
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_point
{
	double			x;
	double			y;
	double			z;
}					t_point;

typedef struct s_ray
{
	t_point			origin;
	t_point			direction;
}					t_ray;

typedef struct s_lst
{
	void			*node;
	void			*next;
}					t_lst;

typedef struct s_solutions
{
	double			t1;
	double			t2;
}					t_solutions;

typedef struct s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct s_sp_params
{
	t_point			center;
	t_color			color;
	double			radius;
	double			reflection;
	double			spec;
}					t_sp_params;

typedef struct s_cy_params
{
	t_point			axe_pos;
	t_point			orient;
	double			diam;
	double			height;
	t_color			color;
	double			reflection;
	double			spec;
}					t_cy_params;

typedef struct s_pl_params
{
	t_point			axe_pos;
	t_point			norm;
	t_color			color;
	double			reflection;
	double			spec;
}					t_pl_params;

typedef struct s_clpar
{
	t_ray			ray;
	double			t_min;
	double			t_max;
	t_lst			*objects;
}					t_clpar;

typedef struct s_cmyk
{
	double			c;
	double			m;
	double			y;
	double			k;
}					t_cmyk;

typedef enum enum_type
{
	SPHERE,
	TRIANGLE,
	PLANE,
	CYLINDER,
	DISC,
	SQUARE
}	t_type;

typedef struct s_obj
{
	t_type			type;
	void			*data;
	t_solutions		(*ft_intersect)(void *data, t_ray ray);
	t_point			(*ft_get_norm)(void *data, t_point intersection, t_ray ray);
	t_color			color;
	double			refl;
	double			spec;
}					t_obj;

typedef struct s_ds_params
{
	t_point			axe_pos;
	t_point			norm;
	t_color			color;
	double			r;
	double			reflection;
	double			spec;
}					t_ds_params;

typedef struct s_cylinder
{
	t_point			axe_pos;
	t_point			orientation;
	t_point			bottom;
	double			diam;
	double			height;
}					t_cylinder;

typedef struct s_camera
{
	t_point			pos;
	t_point			rotation;
	double			fov;
	t_point			save_pos;
	t_point			save_rotation;
}					t_camera;

typedef struct s_parsed_data
{
	t_lst			*objects;
	t_lst			*lights;
	t_lst			*cameras;
}					t_parsed_data;

typedef struct s_exvar
{
	double			width;
	double			height;
	t_lst			*first_cam;
	t_color			background_color;
	t_lst			*memory;
	int				sepia;
	t_color			ambient;
}					t_exvar;

typedef struct s_vector2
{
	int	x;
	int	y;
}				t_vector2;

typedef struct s_mlxdata
{
	void			*img;
	char			*addr;
	int				bbp;
	int				line_len;
	int				endian;
	int				offset;
	t_exvar			*exter;
}					t_mlxdata;

typedef struct s_copar
{
	t_point			p;
	t_point			view;
	t_obj			*obj;
	t_lst			*objects;
	t_lst			*lights;
	t_ray			ray;
}					t_copar;

typedef struct s_mlxvars
{
	void			*mlx;
	void			*win;
	t_mlxdata		img;
	t_parsed_data	*data;
	t_exvar			*test;
}					t_mlxvars;

typedef enum s_ltype
{
	AMBIENT,
	POINT,
	DIRECTION
}			t_ltype;

typedef struct s_light
{
	t_ltype			ltype;
	double			intensity;
	t_point			position;
	t_color			color;
}					t_light;

typedef struct s_sphere
{
	t_point			center; //centre de la sphere
	double			radius; //rayon
}					t_sphere;

typedef struct s_plane
{
	t_point			axe_pos;
	t_point			norm;
}					t_plane;

typedef struct s_disc
{
	t_point			axe_pos;
	t_point			norm;
	t_plane			*plane;
	double			ray;
}					t_disc;

typedef struct s_closest
{
	t_point			inter;
	t_obj			*obj;
	double			t;
}					t_closest;

typedef struct s_matrix
{
	double			d[4][4];
}					t_matrix;

typedef struct s_trpar
{
	t_ray			ray;
	t_lst			*objects;
	t_lst			*lights;
	double			t_min;
	double			t_max;
	int				r_depth;
}					t_trpar;

typedef struct s_covars
{
	t_point			light;
	t_point			ray;
	t_lst			*cur;
	t_closest		blocker;
	t_color			ret;
	t_cmyk			temp;
	double			intensity;
	double			n_l;
	double			r_v;
	double			t_max;
}					t_covars;

int					ft_expose(t_mlxvars *vars);
int					ft_red_cross(t_mlxvars *vars);
int					ft_create_trgb(int t, t_color color, t_exvar *var);
int					ft_key_pressed(int keycode, t_mlxvars *vars);
int					ft_exit(t_mlxvars *vars, char *msg, t_exvar *var);
int					get_next_line(int fd, char **line, t_exvar *var);
int					ft_open_map(char *file, t_exvar *var);
char				**ft_split(char *s, char *delimiters, t_exvar *var);
char				*ft_strnew(int size, t_exvar *var);
void				ft_restore_cam(t_mlxvars *vars, t_exvar *var);
void				ft_switch_cam(t_mlxvars *vars, t_exvar *var);
void				ft_translate_cam(int keycode, t_mlxvars *vars,
						t_exvar *var);
void				ft_rotate_cam(int keycode, t_mlxvars *vars, t_exvar *var);
void				ft_draw(t_mlxvars *vars, t_exvar *var);
void				*ft_memalloc(int size, t_exvar *var);
void				ft_parse_res(char *line, t_exvar *var);
void				ft_free(t_exvar *var);
void				*ft_malloc_save(int size, t_exvar *var);
double				ft_modv(double vx, double vy, double vz);
double				ft_vec_length(t_point a);
double				ft_stof(char *line, t_exvar *var);
double				vec_point(t_point a, t_point b);
t_ray				ft_rotate(int x, int y, t_camera *cam, t_exvar *var);
t_closest			ft_closest(t_clpar params);
t_obj				*ft_create_disc(t_ds_params params, t_exvar *var);
t_obj				*ft_create_sphere(t_sp_params params, t_exvar *var);
t_obj				*ft_create_plane(t_pl_params params, t_exvar *var);
t_obj				*ft_create_cylinder(t_cy_params params, t_exvar *var);
t_obj				*ft_parse_plane(char *line, t_exvar *var);
t_obj				*ft_parse_sphere(char *line, t_exvar *var);
t_light				*ft_parse_amb(char *line, t_exvar *var);
t_light				*ft_parse_light(char *line, t_exvar *var);
t_point				ft_vec_cross(t_point a, t_point b);
t_point				ft_reflect_ray(t_point r, t_point n);
t_point				ft_rotate_normal(t_ray ray, t_point normal,
						t_point intersection);
t_point				vec_norm(t_point vec);
t_point				ft_stop(char *line, t_exvar *var);
t_point				vec_add(t_point a, t_point b);
t_point				vec_mul(double k, t_point a);
t_point				vec_substract(t_point a, t_point b);
t_solutions			ft_intersect_plane(void *data, t_ray ray);
t_lst				*ft_cylinder_caps(t_obj *obj, t_cy_params params,
						t_exvar *var);
t_lst				*ft_parse_cylinder(char *line, t_exvar *var);
t_lst				*ft_lnew(void *content, t_exvar *var);
t_lst				*ft_ladd(t_lst *lst, t_lst *new);
t_color				ft_trace_ray(t_trpar args, t_exvar *var);
t_color				ft_compute_lighting(t_copar args, t_exvar *var,
						t_covars *vars);
t_color				ft_color_average(t_color a, t_color b);
t_color				ft_color_add(t_color a, t_color b);
t_color				ft_stoc(char *line, t_exvar *var);
t_color				ft_color_multiply(double a, t_color color);
t_camera			*ft_parse_camera(char *line, t_exvar *var);
t_exvar				*ft_init_pd2(void);
t_parsed_data		*ft_parser(int argc, char *argv[], t_exvar *var);
t_parsed_data		*ft_parse_processor(char *line, t_parsed_data *data,
						t_exvar *var);
t_parsed_data		*ft_init_pd(t_exvar *var);

#endif