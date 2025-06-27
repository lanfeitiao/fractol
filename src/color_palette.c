/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_palette.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 14:09:09 by jsong         #+#    #+#                 */
/*   Updated: 2024/12/03 15:02:47 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	earth_and_sky_palette(double t)
{
	static const double		limits[] = {0.15, 0.33, 0.67, 0.85, 1.0};
	static const uint8_t	red[] = {255, 255, 135, 0, 0, 255};
	static const uint8_t	green[] = {255, 204, 31, 0, 102, 255};
	static const uint8_t	blue[] = {255, 0, 19, 153, 255, 255};
	t_palette				palette;

	palette.limits = (double *)limits;
	palette.red = (uint8_t *)red;
	palette.green = (uint8_t *)green;
	palette.blue = (uint8_t *)blue;
	palette.segments = 5;
	return (get_color(&palette, t));
}

uint32_t	fire_palette(double t)
{
	const double	limits[3] = {0.17, 0.83, 1.0};
	const uint8_t	red[4] = {0, 255, 255, 255};
	const uint8_t	green[4] = {0, 0, 255, 255};
	const uint8_t	blue[4] = {0, 0, 0, 255};
	t_palette		palette;

	palette.limits = (double *)limits;
	palette.red = (uint8_t *)red;
	palette.green = (uint8_t *)green;
	palette.blue = (uint8_t *)blue;
	palette.segments = 4;
	return (get_color(&palette, t));
}

uint32_t	blue_gold_palette(double t)
{
	const double	limits[2] = {0.5, 1.0};
	const uint8_t	red[3] = {26, 255, 77};
	const uint8_t	green[3] = {26, 153, 77};
	const uint8_t	blue[3] = {255, 0, 255};
	t_palette		palette;

	palette.limits = (double *)limits;
	palette.red = (uint8_t *)red;
	palette.green = (uint8_t *)green;
	palette.blue = (uint8_t *)blue;
	palette.segments = 2;
	return (get_color(&palette, t));
}

uint32_t	hot_and_cold_palette(double t)
{
	const double	limits[4] = {0.16, 0.5, 0.84, 1.0};
	const uint8_t	red[5] = {255, 0, 51, 255, 255};
	const uint8_t	green[5] = {255, 102, 51, 0, 255};
	const uint8_t	blue[5] = {255, 51, 204, 255, 255};
	t_palette		palette;

	palette.limits = (double *)limits;
	palette.red = (uint8_t *)red;
	palette.green = (uint8_t *)green;
	palette.blue = (uint8_t *)blue;
	palette.segments = 4;
	return (get_color(&palette, t));
}

uint32_t	pastels_palette(double t)
{
	const double	limits[5] = {0.180781, 0.418566, 0.627035, 0.858306, 1.0};
	const uint8_t	red[6] = {205, 112, 255, 255, 139, 255};
	const uint8_t	green[6] = {208, 133, 91, 238, 238, 255};
	const uint8_t	blue[6] = {209, 255, 148, 133, 145, 255};
	t_palette		palette;

	palette.limits = (double *)limits;
	palette.red = (uint8_t *)red;
	palette.green = (uint8_t *)green;
	palette.blue = (uint8_t *)blue;
	palette.segments = 5;
	return (get_color(&palette, t));
}
