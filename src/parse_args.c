/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 13:31:25 by jsong         #+#    #+#                 */
/*   Updated: 2024/12/04 11:25:19 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage_and_exit(void)
{
	ft_putendl_fd("\nFractol - Fractal Visualization Program", 2);
	ft_putendl_fd("\nUSAGE:", 2);
	ft_putendl_fd("  ./fractol <fractal_type> [parameters]\n", 2);
	ft_putendl_fd("AVAILABLE FRACTALS:", 2);
	ft_putendl_fd("  mandelbrot, m    : Mandelbrot Set", 2);
	ft_putendl_fd("  julia, j         : Julia Set (optional: cx cy)", 2);
	ft_putendl_fd("  burning_ship, b   : Burning Ship Fractal", 2);
	ft_putendl_fd("PARAMETERS:", 2);
	ft_putendl_fd("  cx cy  : Julia Set complex constant (-2.0 to 2.0)", 2);
	ft_putendl_fd("\nEXAMPLES:", 2);
	ft_putendl_fd("  ./fractol mandelbrot", 2);
	ft_putendl_fd("  ./fractol julia -0.4 0.6", 2);
	ft_putendl_fd("  ./fractol burningship\n", 2);
	ft_putendl_fd("CONTROLS:", 2);
	ft_putendl_fd("  Mouse Wheel      : Zoom in/out", 2);
	ft_putendl_fd("  Arrow Keys       : Move view", 2);
	ft_putendl_fd("  Click Left Mouse : Change color scheme", 2);
	ft_putendl_fd("  ESC              : Exit\n", 2);
	exit(EXIT_FAILURE);
}

static int	is_mandelbrot(char *type)
{
	if (!type)
		return (0);
	if (ft_strncmp(type, "mandelbrot", 11) == 0 || ft_strncmp(type, "m",
			2) == 0)
		return (1);
	else
		return (0);
}

static int	is_burning_ship(char *type)
{
	if (!type)
		return (0);
	if (ft_strncmp(type, "burning_ship", 13) == 0 || ft_strncmp(type, "b",
			2) == 0)
		return (1);
	else
		return (0);
}

static int	is_julia(char *type)
{
	if (!type)
		return (0);
	if (ft_strncmp(type, "julia", 6) == 0 || ft_strncmp(type, "j", 2) == 0)
		return (1);
	else
		return (0);
}

t_fractal_type	get_type(int argc, char *argv[])
{
	if (argc == 2 && is_mandelbrot(argv[1]))
		return (MANDELBROT);
	else if (argc == 2 && is_burning_ship(argv[1]))
		return (BURNING_SHIP);
	else if (argc == 2 && is_julia(argv[1]))
		return (JULIA);
	else if (argc == 4 && is_julia(argv[1]))
	{
		if (ft_atof(argv[2]) > -2.0 && ft_atof(argv[2]) < 2.0
			&& ft_atof(argv[3]) > -2.0 && ft_atof(argv[3]) < 2.0)
			return (JULIA);
		print_usage_and_exit();
	}
	else
		print_usage_and_exit();
	return (0);
}
