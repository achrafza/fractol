/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:41:45 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 03:19:48 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	chosecolor(double x, double y)
{
	int		i;
	double	abs;
	double	x0;
	double	y0;
	double	temp;

	i = 0;
	x0 = 0;
	y0 = 0;
	abs = 0.0;
	temp = x;
	while (abs < 4.0 && i < MAXITER)
	{
		temp = x0;
		x0 = x0 * x0 - y0 * y0 + x;
		y0 = 2 * temp * y0 + y;
		abs = absolute(x0, y0);
		i++;
	}
	if (i == MAXITER)
		return (0xff120919);
	else
		return (figureoutiter(i));
}

void	drawmandelbrotset(t_screen scr)
{
	double	skipx;
	double	skipy;
	double	temp;
	int		i;
	int		j;

	skipx = (scr.value.xmax - scr.value.xmin) / 640;
	skipy = (scr.value.ymax - scr.value.ymin) / 640;
	temp = scr.value.ymin;
	i = 0;
	j = 0;
	while (i < WIDTH)
	{
		j = 0;
		scr.value.ymin = temp;
		while (j < HEIGHT)
		{
			ft_mlx_pixel_put(&scr.img, i, j, chosecolor(scr.value.xmin,
					scr.value.ymin));
			scr.value.ymin += skipy;
			j++;
		}
		scr.value.xmin += skipx;
		i++;
	}
}
