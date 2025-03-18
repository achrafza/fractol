/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:36:11 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 05:47:08 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../mlx/mlx.h"
# include "defines.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_values
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;

}				t_values;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;
typedef struct s_var
{
	void		*win;
	void		*mlx;
}				t_var;
typedef struct s_screen
{
	t_values	value;
	t_var		vars;
	t_data		img;
	int			flag;
	char		**av;
	double		shapeshifter;
}				t_screen;

double			absolute(double x, double y);
void			ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int				closeit(t_screen *scr);
void			drawjulia(t_screen scr);
void			drawmandelbrotset(t_screen scr);
void			drawburningship(t_screen scr);
int				key_listener(int keycode, t_screen *screen);
int				mouse_listener(int mousecode, int x, int y, t_screen *screen);
double			ft_atod(char *str);
int				figureoutiter(int temp, double shapeshifter);
int				checkerav(char **av);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
