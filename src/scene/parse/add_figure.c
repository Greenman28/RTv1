/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hush <hush@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 02:27:13 by hush              #+#    #+#             */
/*   Updated: 2020/05/24 03:01:30 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static
int		scene_read_plane(char **source, t_figure *figure)
{
	t_plane			*plane;
	char 			*text;

	if (source == NULL || figure == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	plane = &(figure->plane);
	if (plane == NULL || (text = *source) == NULL)
		return (ft_puterror(2, "Dereference to NULL pointer"));
	text += ft_strlen(KEYWORD_PLANE);
	figure->mat = (t_material*)read_id(&text);
	figure->type = FIG_PLANE;
	if (*(text++) != '(')
		return (ft_puterror(3, "Expected \'(\' "));
	read_vec(&text, &(plane->n));
	if (!read_comma(&text))
		return (ft_puterror(4, "Expected \',\' "));
	plane->d = read_num(&text);
	if (*(text++) != ')')
		return (ft_puterror(5, "Expected \')\' "));
	*source = text;
	return (0);
}

static
int		scene_read_sphere(char **source, t_figure *figure)
{
	if (source == NULL || figure == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if (*source == NULL)
		return (ft_puterror(2, "Dereferenced to NULL pointer"));
	*source += (int)ft_strlen(KEYWORD_SPHERE) - ft_strlen(KEYWORD_PLANE);
	if (scene_read_plane(source, figure) < 0)
		return (ft_puterror(3, "Cannot read sphere"));
	figure->type = FIG_SPHERE;
	return (0);
}

static
int		scene_read_cone(char **source, t_figure *figure)
{
	t_cone			*cone;
	char 			*text;

	if (source == NULL || figure == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	cone = &(figure->cone);
	if (cone == NULL || (text = *source) == NULL)
		return (ft_puterror(2, "Dereference to NULL pointer"));
	text += ft_strlen(KEYWORD_CONE);
	figure->mat = (t_material*)read_id(&text);
	figure->type = FIG_CONE;
	if (*(text++) != '(')
		return (ft_puterror(3, "Expected \'(\' "));
	read_vec(&text, &(cone->pos));
	if (!read_comma(&text))
		return (ft_puterror(4, "Expected \',\' "));
	read_vec(&text, &(cone->top));
	if (!read_comma(&text))
		return (ft_puterror(5, "Expected \',\' "));
	cone->r = read_num(&text);
	if (*(text++) != ')')
		return (ft_puterror(6, "Expected \')\' "));
	*source = text;
	return (0);
}

static
int		scene_read_cyl(char **source, t_figure *figure)
{
	if (source == NULL || figure == NULL)
		return (ft_puterror(1, "Entered NULL pointer"));
	if (*source == NULL)
		return (ft_puterror(2, "Dereferenced to NULL pointer"));
	*source += (int)ft_strlen(KEYWORD_CYLINDER) - (int)ft_strlen(KEYWORD_CONE);
	if (scene_read_cone(source, figure) < 0)
		return (ft_puterror(3, "Cannot read cylinder"));
	figure->type = FIG_CYL;
	return (0);
}

int			scene_add_figure(t_scene *scene, char **source, t_figure_type type)
{
	int 	code;

	scene->figures = ft_realloc_arr(scene->figures, scene->fig_num,
			scene->fig_num + 1, sizeof(t_figure));
	if (scene->figures == NULL)
		return (ft_puterror(1,"Realloc figure returned NULL"));
	if (type == FIG_PLANE)
		code = scene_read_plane(source, &(scene->figures[scene->fig_num]));
	else if (type == FIG_SPHERE)
		code = scene_read_sphere(source, &(scene->figures[scene->fig_num]));
	else if (type == FIG_CONE)
		code = scene_read_cone(source, &(scene->figures[scene->fig_num]));
	else if (type == FIG_CYL)
		code = scene_read_cyl(source, &(scene->figures[scene->fig_num]));
	else
		code = -1;
	if (code < 0)
		return (ft_puterror(2, "Cannot read figure"));
	scene->fig_num++;
	return (0);
}