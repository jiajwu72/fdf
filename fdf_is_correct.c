/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_is_corrct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:42:15 by jwu               #+#    #+#             */
/*   Updated: 2017/12/29 20:42:16 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		symbole_error(char *s)
{
	int			i;

	i = 0;
	while (*s)
	{
		if (!(ft_isdigit(*s) == 1 || *s == 'x' || *s == ' ' ||
			ft_isalpha(*s) == 1 || *s == '\n' || *s == ',' || *s == '-'))
		{
			ft_putendl("not a valid map (symbole error)");
			return (1);
		}
		i++;
		s++;
	}
	return (0);
}

static int		length_error(char *s)
{
	char		**tab;
	int			st;
	int			l;
	int			i;

	i = -1;
	tab = ft_strsplit(s, '\n');
	st = ft_cnt_parts(*tab, ' ');
	while (tab[++i])
	{
		l = ft_cnt_parts(tab[i], ' ');
		if (l != st)
		{
			ft_putendl("not a valid map (length error)");
			return (1);
		}
	}
	ft_free_sstr(&tab);
	return (0);
}

static void		free_str(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
}

char			**is_correct(char *s)
{
	char		*height;
	char		*color;
	char		**tab;
	int			i;

	i = -1;
	if (length_error(s) == 1 || symbole_error(s) == 1 || s == 0)
		return (0);
	tab = ft_strsplit(ft_replacechar(s, '\n', ' '), ' ');
	while (tab[++i])
	{
		if (ft_haschar(tab[i], ',') == 1)
		{
			height = ft_strsub(tab[i], 0, ft_indexof(tab[i], ','));
			color = ft_strsub(tab[i], ft_indexof(tab[i], ',') + 1,
				ft_strlen(tab[i]) - (ft_indexof(tab[i], ',') + 1));
			if (ft_isint(height) == 0 || ft_isint(color) == 0 ||
				tab[i][ft_indexof(tab[i], ',') + 1] == 0)
				return (0);
			free_str(&height, &color);
		}
		else if (ft_isint(tab[i]) == 0)
			return (0);
	}
	return (tab);
}
