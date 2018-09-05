/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:51:37 by jwu               #+#    #+#             */
/*   Updated: 2017/12/29 14:51:38 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		*get_info(char *file, t_env **e)
{
	int		fd;
	char	*line;
	char	*res;
	int		j;

	(*e)->map->width = 1;
	fd = open(file, O_RDONLY);
	res = ft_strnew(0);
	if ((j = get_next_line(fd, &line)) <= 0)
	{
		ft_putendl("not correct file");
		return (0);
	}
	(*e)->map->length = ft_cnt_parts(line, ' ');
	res = ft_strmerge(ft_strmerge(res, line), ft_one_str("\n"));
	while ((j = get_next_line(fd, &line)) == 1)
	{
		res = ft_strmerge(ft_strmerge(res, line), ft_one_str("\n"));
		(*e)->map->width++;
		line = NULL;
		free(line);
	}
	close(fd);
	return (res);
}
