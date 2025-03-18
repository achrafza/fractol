/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:36:11 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 00:55:19 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../../libft/libft.h"
# include "../../minilibx-linux/mlx.h"
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
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;

}			t_values;

typedef struct list
{
	int		x;
	int		y;
	int		iter;
}			pixel;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;
typedef struct s_var
{
	void *win;
	void *mlx;
}			t_var;
typedef struct s_screen
{
	t_values	value;
	t_var		vars;
	t_data	img;
	int		flag;
	char	**av;
}			t_screen;

// ll chosecolor(double xinit,double yinit,char **av);
double		absolute(double x, double y);
void		ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int	closeit(t_screen *scr);
void		drawjulia(t_screen scr);
void		drawmandelbrotset(t_screen scr);
void	drawburningship(t_screen scr);
int			key_listener(int keycode, t_screen *screen);
int	mouse_listener(int mousecode,int x,int y, t_screen *screen);
double    ft_atod(char *str);
int	figureoutiter(int temp);
#endif
