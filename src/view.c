/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 11:24:06 by jsong         #+#    #+#                 */
/*   Updated: 2024/12/03 16:03:50 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Viewport Zoom Control:
	1. Calculate relative position of target point (0.0 - 1.0)
	2. Apply zoom factor to viewport dimensions:
		- zoom_factor < 1.0: zoom in (smaller viewport)
		- zoom_factor > 1.0: zoom out (larger viewport)
	3. Update boundaries while maintaining target point position
*/

void	update_viewport_zoom(t_viewport *view, double target_cx,
		double target_cy, double zoom_factor)
{
	double	new_width;
	double	new_height;
	double	rel_cx;
	double	rel_cy;

	rel_cx = (target_cx - view->x_min) / (view->x_max - view->x_min);
	rel_cy = (target_cy - view->y_min) / (view->y_max - view->y_min);
	new_width = (view->x_max - view->x_min) * zoom_factor;
	new_height = (view->y_max - view->y_min) * zoom_factor;
	view->x_min = target_cx - rel_cx * new_width;
	view->x_max = view->x_min + new_width;
	view->y_min = target_cy - rel_cy * new_height;
	view->y_max = view->y_min + new_height;
	if (zoom_factor < 1.0)
		view->zoom_level++;
	else if (zoom_factor > 1.0)
		view->zoom_level--;
}

void	update_viewport_move(t_viewport *view, char move_direction)
{
	double	width;
	double	height;
	double	move_cx;
	double	move_cy;

	move_cx = 0;
	move_cy = 0;
	width = view->x_max - view->x_min;
	height = view->y_max - view->y_min;
	if (move_direction == 'U')
		move_cy = -height * MOVE_SPEED;
	else if (move_direction == 'D')
		move_cy = height * MOVE_SPEED;
	else if (move_direction == 'L')
		move_cx = width * MOVE_SPEED;
	else if (move_direction == 'R')
		move_cx = -width * MOVE_SPEED;
	else
		return ;
	view->x_min += move_cx;
	view->x_max += move_cx;
	view->y_min += move_cy;
	view->y_max += move_cy;
}

/*
For each pixel on screen:
	Map pixel coordinates to complex plane coordinates
	Calculate iterations for this point
	Map iterations to color
	Draw pixel in screen
*/
void	render_fractal(void *param)
{
	t_fractol	*f;
	uint32_t	x;
	uint32_t	y;
	double		cx;
	double		cy;

	f = param;
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			cx = ft_mapping_x(x, f->view);
			cy = ft_mapping_y(y, f->view);
			mlx_put_pixel(f->image, x, y,
				map_iterations_to_color(calculate_fractal_iterations(cx, cy,
						*f), f->color_palette, f->view.max_iterations));
		}
	}
}
