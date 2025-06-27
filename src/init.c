/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 12:03:54 by jsong         #+#    #+#                 */
/*   Updated: 2024/12/04 13:03:21 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static mlx_image_t	*init_image(mlx_t *mlx)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image || (mlx_image_to_window(mlx, image, 0, 0) == -1))
	{
		ft_error_msg();
		mlx_terminate(mlx);
	}
	return (image);
}

static void	init_viewport(t_viewport *view, t_fractal_type type)
{
	view->max_iterations = MAX_ITER;
	view->zoom_level = 0;
	if (type == MANDELBROT)
	{
		view->x_min = -2.0;
		view->x_max = 1.0;
		view->y_min = -1.5;
		view->y_max = view->y_min + (view->x_max - view->x_min) * HEIGHT
			/ WIDTH;
	}
	else
	{
		view->x_min = -2.0;
		view->x_max = 2.0;
		view->y_min = -2.0;
		view->y_max = view->y_min + (view->x_max - view->x_min) * HEIGHT
			/ WIDTH;
	}
}

void	init_fractol(t_fractol *fractol, int argc, char *argv[])
{
	ft_memset(fractol, 0, sizeof(t_fractol));
	fractol->type = get_type(argc, argv);
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractol->mlx)
		ft_error_msg();
	fractol->image = init_image(fractol->mlx);
	init_viewport(&fractol->view, fractol->type);
	fractol->color_palette = 0;
	if (fractol->type == JULIA && argc == 4)
	{
		fractol->julia_cx = ft_atof(argv[2]);
		fractol->julia_cy = ft_atof(argv[3]);
	}
	else if (fractol->type == JULIA && argc == 2)
	{
		fractol->julia_cx = 0.285;
		fractol->julia_cy = 0.01;
	}
}
