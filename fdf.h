/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:11:24 by jwu               #+#    #+#             */
/*   Updated: 2017/12/22 17:45:24 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/*
** windows/objet
*/

# define SIZEWIN			1200

/*
**  touche clavier
*/

# define KEY_ESC			53
# define MOVE_UP       		126
# define MOVE_DOWN     		125
# define MOVE_LEFT			123
# define MOVE_RIGHT    		124

# define ZOOM_IN       		69
# define ZOOM_OUT      		78

# define GROW				5
# define SHRINK				1
# define INIT				49
# define CHANGEC			8

/*
** move pixel
*/
# define PIXEL_MOVE_UP		-50
# define PIXEL_MOVE_DOWN	50
# define PIXEL_MOVE_LEFT	-50
# define PIXEL_MOVE_RIGHT	50

# define PIXEL_ZOOM_IN		1.1
# define PIXEL_ZOOM_OUT		0.9

# define PIXEL_GROW			1.1
# define PIXEL_SHRINK		0.9
# define PIXEL_ROT			20

/*
** struct
*/
typedef struct				s_map
{
	int						length;
	int						width;
	int						**coords;
	int						*colors;
	int						x_move;
	int						y_move;
	double					zoom;
	double					height;
	char					**sstr;
	double					beta;
	int						change;
	int						min;
	int						modif;
}							t_map;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	t_map					*map;
	char					*pixel_img;
	int						bpp;
	int						ed;
	int						s_line;
}							t_env;

typedef struct				s_fonc_affine
{
	double					a;
	double					b;
}							t_fonc_affine;

/*
** get char information of fdf file
*/
char						*get_info(char *file, t_env **e);

/*
** gestion of error
*/
char						**is_correct(char *s);

/*
** parsing
*/
int							init_coords_colors(t_map **map, char **s);
int							parsing_map(char *file, t_env *e);

/*
** draw
*/
void						drawlines(int **pts, t_env *e);
void						draw_point_inst(int i, int j, t_env *e, int total);
void						draw_points(t_env *e);
void						draw_point_inst(int i, int j, t_env *e, int total);
void						draw(t_env *e);

/*
** hook
*/
int							key_init_hook(int keycode, t_env *e);
int							key_changecolor_hook(int keycode, t_env *e);
int							key_grow_shrink_key_hook(int keycode, t_env *e);
int							key_hook_translation(int keycode, t_env *e);
int							key_hook_zoom(int keycode, t_env *e);
int							my_key(int keycode, t_env *e);
int							expose_hook(t_env *env);

/*
** calcul
*/
int							absolue(int *a, int *b);
t_fonc_affine				define_aff(int *p1, int *p2);
int							color_instance_t(char *a, char *b, int t, int z);
double						calcul_aff(int x, t_fonc_affine f);
double						calcul_x(int y, t_fonc_affine f);
void						put_point(int a, int b, t_env e, int color);
int							point_out_window(int *a);
int							define_color(t_map *map, int k, int i, int j);
int							color_height(int z);

/*
**free
*/
void						free_env(t_env *e);

#endif
