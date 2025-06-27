/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculation.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jianisong <jianisong@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 21:54:59 by jianisong     #+#    #+#                 */
/*   Updated: 2024/12/03 16:04:24 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	CASE MANDELBROT:
		z = 0
		c = input complex point
		For each iteration up to max_iterations:
			z(n+1) = (cx_n + cy_n*i)^2 + c where z(n) =cx_n + cy_n*i
			If magnitude(z) > 2:
				break
		Return iterations
*/
static int	calculate_mandelbrot(double cx, double cy, int max_iterations)
{
	int		iter;
	double	cx_new;
	double	cy_new;
	double	temp;

	iter = 0;
	cx_new = 0;
	cy_new = 0;
	while (iter < max_iterations && cx_new * cx_new + cy_new * cy_new <= 4)
	{
		temp = cx_new * cx_new - cy_new * cy_new + cx;
		cy_new = 2 * cx_new * cy_new + cy;
		cx_new = temp;
		iter++;
	}
	return (iter);
}

/*
	CASE BURNING_SHIP:
		z = 0
		c = input complex point
		For each iteration up to max_iterations:
			z(n+1) = (|cx_n| + |cy_n|*i)^2 + c where z(n) =cx_n + cy_n*i
			If magnitude(z) > 2:
				break
		Return iterations
*/
static int	calculate_burning_ship(double cx, double cy, int max_iterations)
{
	int		iter;
	double	cx_new;
	double	cy_new;
	double	temp;

	iter = 0;
	cx_new = 0;
	cy_new = 0;
	cy = -cy;
	while (iter < max_iterations && cx_new * cx_new + cy_new * cy_new <= 4)
	{
		temp = cx_new * cx_new - cy_new * cy_new + cx;
		cy_new = fabs(2 * cx_new * cy_new) + cy;
		cx_new = temp;
		iter++;
	}
	return (iter);
}

/*
	CASE JULIA:
		z = input complex point
		c = predefined complex constant
		For each iteration up to max_iterations:
			z = z^2 + c
			If magnitude(z) > 2:
				break
		Return iterations
*/
static int	calculate_julia(double cx, double cy, t_fractol fractol)
{
	int		iter;
	double	cx_new;
	double	cy_new;
	double	temp;

	iter = 0;
	cx_new = cx;
	cy_new = cy;
	while (iter < fractol.view.max_iterations)
	{
		temp = cx_new * cx_new - cy_new * cy_new + fractol.julia_cx;
		cy_new = 2 * cx_new * cy_new + fractol.julia_cy;
		cx_new = temp;
		if (cx_new * cx_new + cy_new * cy_new > 4)
			break ;
		iter++;
	}
	return (iter);
}

/*
	wrapper function to calculate iterations for a given point
 */
int	calculate_fractal_iterations(double cx, double cy, t_fractol fractol)
{
	if (fractol.type == MANDELBROT)
		return (calculate_mandelbrot(cx, cy, fractol.view.max_iterations));
	else if (fractol.type == JULIA)
		return (calculate_julia(cx, cy, fractol));
	else if (fractol.type == BURNING_SHIP)
		return (calculate_burning_ship(cx, cy, fractol.view.max_iterations));
	else
	{
		ft_putendl_fd("Error: fractal type not supported", 2);
		return (-1);
	}
}
