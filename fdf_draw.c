/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:54:55 by jwu               #+#    #+#             */
/*   Updated: 2017/12/27 16:54:56 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		point_out_window(int *a)
{
	if (a[0] <= 0 || a[0] >= SIZEWIN ||
		a[1] <= 0 || a[1] >= SIZEWIN)
		return (1);
	return (0);
}

void	put_point(int a, int b, t_env e, int color)
{
	int i;

	i = (a * 4) + (b * e.s_line);
	e.pixel_img[i] = color;
	e.pixel_img[++i] = color >> 8;
	e.pixel_img[++i] = color >> 16;
}

void	draw(t_env *e)
{
	int				**coords;
	int				*colors;

	coords = e->map->coords;
	colors = e->map->colors;
	drawlines(coords, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
