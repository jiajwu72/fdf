/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_absolue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:35:39 by jwu               #+#    #+#             */
/*   Updated: 2018/01/05 15:35:40 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		abss(int a, int b)
{
	return (a > b ? a - b : b - a);
}

int				absolue(int *a, int *b)
{
	if (a[0] == b[0])
		return (abss(a[1], b[1]));
	else if (a[1] == b[1])
		return (abss(a[0], b[0]));
	else
	{
		if (abss(a[0], b[0]) > abss(a[1], b[1]))
			return (abss(a[0], b[0]));
		else
			return (abss(a[1], b[1]));
	}
}
