/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 10:51:34 by jsong         #+#    #+#                 */
/*   Updated: 2024/12/03 16:06:55 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	ft_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint8_t	interpolate(uint8_t start, uint8_t end, double factor)
{
	return (start + (uint8_t)((end - start) * factor));
}

/*
	Maps value t (0.0-1.0) to color using palette segments
	Each segment interpolates between two colors based on t
*/
uint32_t	get_color(t_palette *palette, double t)
{
	double	segment_start;
	double	nt;
	uint8_t	rgb[3];
	int		i;

	i = 0;
	while (i < palette->segments)
	{
		if (t <= palette->limits[i])
		{
			if (i == 0)
				segment_start = 0;
			else
				segment_start = palette->limits[i - 1];
			nt = (t - segment_start) / (palette->limits[i] - segment_start);
			rgb[0] = interpolate(palette->red[i], palette->red[i + 1], nt);
			rgb[1] = interpolate(palette->green[i], palette->green[i + 1], nt);
			rgb[2] = interpolate(palette->blue[i], palette->blue[i + 1], nt);
			return (ft_pixel(rgb[0], rgb[1], rgb[2], 255));
		}
		i++;
	}
	return (ft_pixel(0, 0, 0, 255));
}

uint32_t	map_iterations_to_color(int iteration, int palette_nbr,
		int max_iteration)
{
	double	t;

	if (iteration == max_iteration)
		return (ft_pixel(0, 0, 0, 255));
	t = (double)iteration / max_iteration;
	if (palette_nbr == 0)
		return (earth_and_sky_palette(t));
	else if (palette_nbr == 1)
		return (fire_palette(t));
	else if (palette_nbr == 2)
		return (blue_gold_palette(t));
	else if (palette_nbr == 3)
		return (hot_and_cold_palette(t));
	else if (palette_nbr == 4)
		return (pastels_palette(t));
	else
		return (ft_pixel(0, 0, 0, 255));
}
