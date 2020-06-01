/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:05:54 by hush              #+#    #+#             */
/*   Updated: 2020/06/02 02:25:25 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene		*scene_init()
{
	t_scene		*scene;

	scene = (t_scene*)ft_malloc(sizeof(t_scene));
	if (scene == NULL)
		return (ft_puterr_null(1, "scene_create():"
								  "cannot malloc scene struct"));
	scene->materials = (t_material*)ft_malloc(sizeof(t_material));
	if (scene->materials == NULL)
		return (ft_puterr_null(1, "scene_create():"
								  "cannot malloc materials"));
	scene->mat_num = 1;
	material_set_default(&(scene->materials[0]));
	scene->fig_num = 0;
	scene->figures = NULL;
	scene->light_num = 0;
	scene->lights = NULL;
	scene->cam_num = 0;
	scene->cameras = NULL;
	return (scene);
}

void		scene_free(t_scene *scene)
{
	if (scene == NULL)
		return ;
	ft_free(scene->figures);
	ft_free(scene->materials);
	ft_free(scene->lights);
	ft_free(scene);
}

char		*scene_to_str(t_scene *scene)
{
	size_t		i;
	char		*res;

	if (scene == NULL)
		return (ft_strdup("(null)"));
	res = ft_strdup("scene:\n{\n  Materials:");
	i = 0;
	while (i < scene->mat_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, material_to_str(&(scene->materials[i++])));
	}
	res = ft_str_add(res, "\n  Lights:");
	i = 0;
	while (i < scene->light_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, light_to_str(&(scene->lights[i++])));
	}
	res = ft_str_add(res, "\n  Cameras:");
	i = 0;
	while (i < scene->cam_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, camera_to_str(&(scene->cameras[i++])));
	}
	res = ft_str_add(res, "\n  Figures:");
	i = 0;
	while (i < scene->fig_num)
	{
		res = ft_str_add(res, "\n    ");
		res = ft_strjoin_free(res, figure_to_str(&(scene->figures[i++])));
	}
	res = ft_str_add(res, "\n}\n");
	return (res);
}
