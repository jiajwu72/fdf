/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 17:33:46 by jwu               #+#    #+#             */
/*   Updated: 2017/12/27 17:33:47 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					get_min(char **str)
{
	int		min;

	min = ft_atoi(*str);
	while (*str)
	{
		if (ft_atoi(*str) < min)
			min = ft_atoi(*str);
		str++;
	}
	return (min);
}

void				init_coord(t_map *map, int *t, char *s, int i)
{
	int		tmp;

	t[2] = ft_atoi(s);
	tmp = t[0];
	t[0] = ((i % (map->length)) - (i / (map->length))) * map->length / 2;
	t[1] = ((i % (map->length)) + (i / (map->length))) * map->width / 2;
	t[3] = '\0';
}

void				init_c(t_map *m, int **coords)
{
	int		a;
	int		b;
	double	c;
	double	d;

	a = coords[m->length - 1][0] - coords[0][0];
	b = coords[m->length * (m->width - 1)][1] - coords[0][1];
	c = sqrt(a * a + b * b);
	d = 400 / c;
	if (c > 30000)
		d /= 5;
	while (*(coords))
	{
		(*(coords))[0] = (*(coords))[0] * d * m->zoom + m->x_move;
		(*(coords))[1] = (*(coords))[1] * d * m->zoom
		+ m->y_move - m->height * (*coords)[2];
		(coords)++;
	}
}

int					init_coords_colors(t_map **map, char **s)
{
	int		ind;
	int		i;
	char	*t;

	i = -1;
	while (s[++i])
	{
		ind = ft_indexof(s[i], 'x');
		init_coord(*map, (*map)->coords[i], s[i], i);
		if ((*map)->colors[i] == 0)
		{
			if (ind < 0)
				(*map)->colors[i] = color_height((*map)->coords[i][2]);
			else
			{
				t = ft_strsub(s[i], ind + 1, ft_strlen(s[i]) - (ind + 1));
				(*map)->colors[i] = ft_hexa_to_int(t);
				free(t);
			}
		}
	}
	(*map)->coords[i] = 0;
	(*map)->colors[i] = 0;
	init_c(*map, (*map)->coords);
	return (1);
}

int					parsing_map(char *file, t_env *e)
{
	char	**info;

	(*e).map = malloc(sizeof(t_map));
	e->map->zoom = 1;
	e->map->x_move = 500;
	e->map->y_move = 300;
	e->map->height = 2;
	if (!(file = get_info(file, &e)))
		return (0);
	if (!(info = is_correct(file)))
		return (0);
	(*e).map->coords = ft_iintnew(ft_sstrlen(info), 3);
	(*e).map->colors = ft_intnew(ft_sstrlen(info) + 1);
	(*e).map->sstr = ft_sstrnew(ft_sstrlen(info), ft_strlen(*info));
	(*e).map->sstr = ft_sstrcpy((*e).map->sstr, info);
	(*e).map->beta = 0;
	(*e).map->modif = 0;
	init_coords_colors(&(e->map), info);
	(*e).map->change = 0;
	(*e).map->min = get_min(info);
	ft_free_sstr(&info);
	free(file);
	return (1);
}
