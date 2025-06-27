/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsong <jsong@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 12:51:30 by jsong         #+#    #+#                 */
/*   Updated: 2024/12/04 11:25:36 by jsong         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 900
# define HEIGHT 900
# define ZOOM_FACTOR 0.5
# define MOVE_SPEED 0.1
# define MAX_ITER 100

# include "MLX42/MLX42.h"
# include "libft.h"
# include <math.h>
# include <stdint.h>

typedef struct s_viewport
{
	double			x_min;
	double			x_max;
	double			y_min;
	double			y_max;
	int				max_iterations;
	int				zoom_level;
}					t_viewport;

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	TRICORN,
	NEWTON
}					t_fractal_type;

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_fractal_type	type;
	double			julia_cx;
	double			julia_cy;
	t_viewport		view;
	int				color_palette;
}					t_fractol;

typedef struct s_palette
{
	double			*limits;
	uint8_t			*red;
	uint8_t			*green;
	uint8_t			*blue;
	int				segments;
}					t_palette;

// initialization related functions
t_fractal_type		get_type(int argc, char *argv[]);
void				init_fractol(t_fractol *fractol, int argc, char *argv[]);

// view related functions
void				update_viewport_zoom(t_viewport *view, double target_cx,
						double target_cy, double zoom_factor);
void				update_viewport_move(t_viewport *view, char move_direction);
void				render_fractal(void *param);
int					calculate_fractal_iterations(double cx, double cy,
						t_fractol fractol);

// color related functions
uint32_t			map_iterations_to_color(int iteration, int palette,
						int max_iteration);
uint32_t			get_color(t_palette *palette, double t);
uint32_t			earth_and_sky_palette(double t);
uint32_t			fire_palette(double t);
uint32_t			blue_gold_palette(double t);
uint32_t			hot_and_cold_palette(double t);
uint32_t			pastels_palette(double t);

// util functions
void				ft_error_msg(void);
double				ft_mapping_x(uint32_t x, t_viewport view);
double				ft_mapping_y(uint32_t y, t_viewport view);
double				ft_atof(char *s);

// event related functions
void				key_hook(mlx_key_data_t keydata, void *param);
void				zoom_hook_scroll(double xdelta, double ydelta, void *param);
void				change_color_hook(mouse_key_t button, action_t action,
						modifier_key_t mods, void *param);
#endif