/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/20 14:38:00 by jsong         #+#    #+#                 */
/*   Updated: 2024/12/04 12:39:51 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Main function for fractol program
	1. Initialize fractal settings based on command line args
	2. Setup event hooks for:
		- Continuous rendering (loop_hook)
		- Keyboard controls (key_hook)
		- Mouse zoom (scroll_hook)
		- Mouse click (mouse_hook)
	3. Start event loop and cleanup on exit
*/
int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	init_fractol(&fractol, argc, argv);
	mlx_loop_hook(fractol.mlx, render_fractal, &fractol);
	mlx_key_hook(fractol.mlx, key_hook, &fractol);
	mlx_scroll_hook(fractol.mlx, zoom_hook_scroll, &fractol);
	mlx_mouse_hook(fractol.mlx, change_color_hook, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (EXIT_SUCCESS);
}
