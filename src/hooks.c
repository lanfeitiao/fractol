/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 16:01:52 by jsong         #+#    #+#                 */
/*   Updated: 2025/06/27 14:32:28 by jianisong     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(fractol->mlx);
		else if (keydata.key == MLX_KEY_LEFT)
			update_viewport_move(&fractol->view, 'L');
		else if (keydata.key == MLX_KEY_RIGHT)
			update_viewport_move(&fractol->view, 'R');
		else if (keydata.key == MLX_KEY_UP)
			update_viewport_move(&fractol->view, 'U');
		else if (keydata.key == MLX_KEY_DOWN)
			update_viewport_move(&fractol->view, 'D');
	}
}

void	zoom_hook_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	double		target_cx;
	double		target_cy;
	int32_t		mouse_pos_x;
	int32_t		mouse_pos_y;

	(void)xdelta;
	fractol = param;
	mlx_get_mouse_pos(fractol->mlx, &mouse_pos_x, &mouse_pos_y);
	target_cx = ft_mapping_x(mouse_pos_x, fractol->view);
	target_cy = ft_mapping_y(mouse_pos_y, fractol->view);
	if (ydelta > 0)
		update_viewport_zoom(&fractol->view, target_cx, target_cy, ZOOM_FACTOR);
	else if (ydelta < 0)
		update_viewport_zoom(&fractol->view, target_cx, target_cy, (1
				/ ZOOM_FACTOR));
	else
		return ;
}

void	change_color_hook(mouse_key_t button, action_t action,
		modifier_key_t mods, void *param)
{
	t_fractol	*fractol;

	fractol = param;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		fractol->color_palette = (fractol->color_palette + 1) % 5;
		ft_putendl_fd("Changing color palette", 1);
	}
	else
		return ;
}
