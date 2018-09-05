/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:18:48 by jwu               #+#    #+#             */
/*   Updated: 2017/12/27 16:18:52 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int							my_key(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		ft_putendl("Au revoir");
		mlx_destroy_window(e->mlx, e->win);
		free_env(e);
		exit(0);
	}
	key_hook_zoom(keycode, e);
	key_hook_translation(keycode, e);
	key_grow_shrink_key_hook(keycode, e);
	key_init_hook(keycode, e);
	key_changecolor_hook(keycode, e);
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, SIZEWIN, SIZEWIN);
	e->pixel_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->ed));
	draw(e);
	return (0);
}

int							expose_hook(t_env *env)
{
	draw(env);
	return (0);
}

t_env						init_win(t_env env)
{
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, SIZEWIN, SIZEWIN, "FDF");
	env.img = mlx_new_image(env.mlx, SIZEWIN, SIZEWIN);
	env.pixel_img = mlx_get_data_addr(env.img, &(env.bpp),
		&(env.s_line), &(env.ed));
	return (env);
}

int							help(void)
{
	ft_putendl("---------------------------------------");
	ft_putendl("deplacement : keys up down left right");
	ft_putendl("monter en altitude: g");
	ft_putendl("descends em altitude: s");
	ft_putendl("zoomer : +/-");
	ft_putendl("changer de couleur: c");
	ft_putendl("revenir a la position initiale: espace");
	ft_putendl("---------------------------------------");
	return (0);
}

int							main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		ft_putstr("usage: ./fdf source_file\n");
	else if (parsing_map(av[1], &env) == 1)
	{
		help();
		env = init_win(env);
		mlx_key_hook(env.win, my_key, &env);
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
