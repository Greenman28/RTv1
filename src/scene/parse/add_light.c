/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 03:11:40 by hush              #+#    #+#             */
/*   Updated: 2020/06/17 22:58:51 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		scene_read_light(char **source, t_light *light)
{
	char		*text;

	if (source == NULL || light == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if ((text = *source) == NULL)
		return (ft_puterror(2, "Dereference to NULL pointer"));
	text += ft_strlen(KEYWORD_LIGHT);
	if (*(text++) != '(')
		return (ft_puterror(3, "Expected \'(\' "));
	if (read_vec(&text, &(light->pos)) < 0)
		return (ft_puterror(4, "Cannot read position vector"));
	if (read_comma(&text) < 0)
		return (ft_puterror(5, "Expected \',\' "));
	if (read_vec(&text, &(light->col)) < 0)
		return (ft_puterror(4, "Cannot read color vector"));
	if (read_comma(&text) < 0)
		return (ft_puterror(5, "Expected \',\' "));
	light->power = read_num(&text);
	if (*(text++) != ')')
		return (ft_puterror(6, "Expected \')\' "));
	*source = text;
	return (0);
}

int				scene_add_light(t_scene *scene, char **source)
{
	if (scene == NULL)
		return (ft_puterror(1, "scene is NULL pointer"));
	scene->lights = ft_realloc_arr(scene->lights, scene->light_num,
			scene->light_num + 1, sizeof(t_figure));
	if (scene->figures == NULL)
		return (ft_puterror(2, "Realloc light returned NULL"));
	if (scene_read_light(source, &(scene->lights[scene->light_num])) < 0)
		return (ft_puterror(3, "Cannot read light"));
	scene->lights[scene->light_num].id = scene->light_num;
	scene->light_num++;
	return (0);
}
