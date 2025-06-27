/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 15:40:35 by jsong         #+#    #+#                 */
/*   Updated: 2024/12/03 16:30:56 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_msg(void)
{
	char	*error_msg;

	error_msg = (char *)mlx_strerror(mlx_errno);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

double	ft_mapping_x(uint32_t x, t_viewport view)
{
	double	cx;

	cx = view.x_min + (view.x_max - view.x_min) * (double)x / WIDTH;
	return (cx);
}

double	ft_mapping_y(uint32_t y, t_viewport view)
{
	double	cy;

	cy = view.y_max - (view.y_max - view.y_min) * (double)y / HEIGHT;
	return (cy);
}

double	ft_atof(char *s)
{
	double	result;
	double	decimal;
	int		sign;

	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	result = 0;
	while (*s >= '0' && *s <= '9')
		result = result * 10 + *s++ - '0';
	if (*s == '.')
	{
		s++;
		decimal = 0.1;
		while (*s >= '0' && *s <= '9')
		{
			result += (*s - '0') * decimal;
			decimal *= 0.1;
			s++;
		}
	}
	return (result * sign);
}
