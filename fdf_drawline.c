/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:57:46 by jwu               #+#    #+#             */
/*   Updated: 2018/01/04 16:57:47 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			drawline(int *p1, int *p2, int color, t_env *e)
{
	double	dd;
	double	x;
	double	y;
	double	dx;
	double	dy;

	x = p1[0];
	y = p1[1];
	dx = p2[0] - x;
	dy = p2[1] - y;
	dd = sqrt((dx * dx) + (dy * dy));
	dx = dx / dd;
	dy = dy / dd;
	while (dd-- > 0)
	{
		put_point(x, y, *e, color);
		x += dx;
		y += dy;
	}
}

void			drawlines(int **pts, t_env *e)
{
	int				i;

	i = -1;
	while (pts[(++i) + 1])
	{
		if (i % e->map->length != e->map->length - 1 &&
			point_out_window(pts[i]) == 0 && point_out_window(pts[i + 1]) == 0)
			drawline(pts[i], pts[i + 1], e->map->colors[i + 1], e);
		if (i / e->map->length < e->map->width - 1
			&& point_out_window(pts[i]) == 0
			&& point_out_window(pts[i + e->map->length]) == 0)
			drawline(pts[i], pts[i + e->map->length], e->map->colors[i + 1], e);
	}
}
