/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:23:16 by kcharla           #+#    #+#             */
/*   Updated: 2020/06/18 01:13:25 by hush             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include "rt_parser.h"
# include "rt_num.h"
# include "rt_s.h"
# include "rt_scene.h"
# include "rt_trace.h"
# include "rt_utils.h"
# include "rt_vector.h"
# include "rt_camera.h"

# define WIN_WIDTH  640
# define WIN_HEIGHT 640

# define VEL_DELTA 0.2

# define EPSILON   0.0001

/*
** events_1.c
*/

void				on_key_down(t_rt *rtv1, SDL_Scancode scancode);
void				on_key_up(t_rt *rtv1, SDL_Scancode scancode);
void				on_mouse_down(t_rt *rtv1, SDL_Scancode scancode);
void				on_mouse_move(t_rt *rtv1, int x, int y);
void				on_mouse_up(t_rt *rtv1, SDL_Scancode scancode);

/*
** events_2.c
*/

void				on_num_down(t_rt *rtv1, SDL_Scancode scancode);

/*
** window.c
*/

int					win_update_from_camera(t_window *win, t_camera *cam);
int					window_update_texture(t_window *win, t_texture *texture);
void				window_free(t_window *win);
t_window			*window_init(size_t w, size_t h, const char *name);
int					window_render(t_window *win);

/*
** loop.c
*/

int					rt_loop(t_rt *rtv1);

/*
** texture.c
*/

void				texture_free(t_texture *texture);
t_texture			*texture_init(size_t w, size_t h);
void				texture_fill(t_texture *texture, t_col col);
void				texture_put_pixel(t_texture *texture, t_col col,
						size_t x, size_t y);

/*
** rt.c
*/

t_rt				*rt_new(int ac, char **args);
void				rt_quit(t_rt *rtv1);

#endif
