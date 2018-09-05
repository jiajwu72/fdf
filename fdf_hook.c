/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 17:22:29 by jwu               #+#    #+#             */
/*   Updated: 2017/12/27 17:22:30 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook_zoom(int keycode, t_env *e)
{
	if (keycode == ZOOM_IN)
	{
		e->map->zoom *= PIXEL_ZOOM_IN;
		init_coords_colors(&(e->map), e->map->sstr);
	}
	else if (keycode == ZOOM_OUT)
	{
		e->map->zoom *= PIXEL_ZOOM_OUT;
		init_coords_colors(&(e->map), e->map->sstr);
	}
	return (0);
}

int		key_hook_translation(int keycode, t_env *e)
{
	if (keycode == MOVE_UP || keycode == MOVE_DOWN ||
		keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
	{
		if (keycode == MOVE_UP)
			e->map->y_move += PIXEL_MOVE_UP;
		else if (keycode == MOVE_DOWN)
			e->map->y_move += PIXEL_MOVE_DOWN;
		else if (keycode == MOVE_LEFT)
			e->map->x_move += PIXEL_MOVE_LEFT;
		else if (keycode == MOVE_RIGHT)
			e->map->x_move += PIXEL_MOVE_RIGHT;
		init_coords_colors(&(e->map), e->map->sstr);
	}
	return (0);
}

int		key_grow_shrink_key_hook(int keycode, t_env *e)
{
	if (keycode == GROW)
	{
		e->map->height *= PIXEL_GROW;
		init_coords_colors(&(e->map), e->map->sstr);
	}
	if (keycode == SHRINK)
	{
		e->map->height *= PIXEL_SHRINK;
		init_coords_colors(&(e->map), e->map->sstr);
	}
	return (0);
}

int		key_changecolor_hook(int keycode, t_env *e)
{
	int i;
	int len;

	if (keycode == 8)
	{
		e->map->change = (e->map->change + 1) % 3;
		i = -1;
		len = ft_intlen(e->map->colors);
		while (e->map->colors[++i])
		{
			if (e->map->coords[i][2] == e->map->min)
				e->map->colors[i] = 0xD2F200;
			else if (e->map->coords[i][2] < 10)
			{
				if (e->map->change == 0)
					e->map->colors[i] = 0x32A862;
				else if (e->map->change == 1)
					e->map->colors[i] = 0x000092;
				else
					e->map->colors[i] = 0xFF0001;
			}
		}
	}
	return (0);
}

int		key_init_hook(int keycode, t_env *e)
{
	if (keycode == INIT)
	{
		e->map->zoom = 1;
		e->map->x_move = 200;
		e->map->y_move = 200;
		e->map->height = 1;
		e->map->change = -1;
		init_coords_colors(&(e->map), e->map->sstr);
	}
	return (0);
}
