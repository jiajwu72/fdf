/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_gere_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:55:13 by jwu               #+#    #+#             */
/*   Updated: 2018/01/04 17:55:14 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					define_color(t_map *map, int k, int i, int j)
{
	int total;

	total = absolue(map->coords[i], map->coords[j]);
	if (k == 0)
		return (map->colors[i]);
	else if (k == total - 1)
		return (map->colors[j]);
	else
	{
		if (map->coords[i][2] > map->coords[j][2])
			return (map->colors[i]);
		return (map->colors[j]);
	}
}

int					color_height(int z)
{
	int color;

	if (z < 0)
		color = 0x0D6386;
	else if (z >= 0 && z < 10)
		color = 0x32A862;
	else if (z >= 10 && z < 20)
		color = 0x8FC89A;
	else if (z >= 20 && z < 50)
		color = 0xFAECBE;
	else if (z >= 50 && z < 70)
		color = 0x996E56;
	else if (z >= 70)
		color = 0xE0D3CC;
	else
		color = 0;
	return (color);
}
