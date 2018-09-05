/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:11:08 by jwu               #+#    #+#             */
/*   Updated: 2018/01/04 17:11:09 by jwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fonc_affine		define_aff(int *p1, int *p2)
{
	t_fonc_affine f;

	f.a = (double)(p2[1] - p1[1]) / (double)(p2[0] - p1[0]);
	f.b = p1[1] - f.a * p1[0];
	return (f);
}

double				calcul_aff(int x, t_fonc_affine f)
{
	return (f.a * (double)x + f.b);
}

double				calcul_x(int y, t_fonc_affine f)
{
	return ((y - (double)f.b) / ((double)f.a));
}
