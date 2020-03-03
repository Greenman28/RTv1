/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 04:36:18 by kcharla           #+#    #+#             */
/*   Updated: 2020/03/03 15:45:15 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			rtv1_init(t_rtv1 **rtv1)
{
	t_rtv1		*new;

	if (rtv1 == NULL)
		return (ft_puterror(1, "rtv1_init(): pointer is NULL"));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (ft_puterror(2, "rtv1_init(): cannot init SDL_VIDEO"));
	if ((new = (t_rtv1*)malloc(sizeof(t_rtv1))) == NULL)
		return (ft_puterror(3, "rtv1_init(): cannot malloc rtv1"));
	if (window_init(&(new->window), WIN_WIDTH, WIN_HEIGHT) < 0)
		return (ft_puterror(4, "rtv1_init(): cannot init window"));
	if (camera_init_static(&(new->camera)) < 0)
		return (ft_puterror(5, "rtv1_init(): cannot init camera"));
	new->vel_forward = 0;
	new->vel_right = 0;
	new->vel_up = 0;
	*rtv1 = new;
	return (0);
}
