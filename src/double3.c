/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 09:37:27 by kcharla           #+#    #+#             */
/*   Updated: 2020/02/18 23:51:33 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_double3	d3_plus(t_double3 a, t_double3 b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

t_double3	d3_minus(t_double3 a, t_double3 b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return (a);
}

t_double3	d3_mult(t_double3 a, double b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}

double		d3_dist_sqr(t_double3 a, t_double3 b)
{
	double		dist_sqr;

	dist_sqr = (a.x - b.x) * (a.x - b.x);
	dist_sqr += (a.y - b.y) * (a.y - b.y);
	dist_sqr += (a.z - b.z) * (a.z - b.z);
	return (dist_sqr);
}

double		d3_dist(t_double3 a, t_double3 b)
{
	return (sqrt(d3_dist_sqr(a, b)));
}

double		d3_len(t_double3 a)
{
	t_double3	zero;

	zero = (t_double3){0, 0, 0};
	return (d3_dist(zero, a));
}

char		*d3_to_str(t_double3 a)
{
	char		*res;

	res = ft_strjoin_free(ft_strdup("("), ft_ldtoa(a.x));
	res = ft_strjoin_free(res, ft_strdup(" | "));
	res = ft_strjoin_free(res, ft_ldtoa(a.y));
	res = ft_strjoin_free(res, ft_strdup(" | "));
	res = ft_strjoin_free(res, ft_ldtoa(a.z));
	res = ft_strjoin_free(res, ft_strdup(")"));
	return (res);
}

char		*d3_to_str_color(t_double3 a)
{
	char		*res;

	res = ft_strjoin_free(ft_strdup("(\033[0;31m"), ft_ldtoa(a.x));
	res = ft_strjoin_free(res, ft_strdup("\033[0m | \033[0;32m"));
	res = ft_strjoin_free(res, ft_ldtoa(a.y));
	res = ft_strjoin_free(res, ft_strdup("\033[0m | \033[0;34m"));
	res = ft_strjoin_free(res, ft_ldtoa(a.z));
	res = ft_strjoin_free(res, ft_strdup("\033[0m)"));
	return (res);
}