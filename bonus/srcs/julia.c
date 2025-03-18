/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:14:11 by azahid            #+#    #+#             */
/*   Updated: 2025/03/17 21:28:53 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


static ll	chosecolor(double x, double y, char **av,double shape)
{
	int		i;
	double	abs;
	double	x0;
	double	y0;
	double	temp;

	i = 0;
  
	(void)(av);
 	x0 = ft_atod(av[2]);
	y0 = ft_atod(av[3]);
	abs = 0.0;
	temp = x;
	while (abs < 4.0 && i < MAXITER)
	{
		temp = x;
		x = x * x - y * y + x0;
		y = 2 * temp * y + y0;
		abs = absolute(x, y);
		i++;
	}
	if (i == MAXITER)
		return (0xff120919);
	else
		return (figureoutiter(i,shape));
}

void	drawjulia(t_screen scr)
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
					scr.value.ymin, scr.av,scr.shapeshifter));
			scr.value.ymin += skipy;
			j++;
		}
		scr.value.xmin += skipx;
		i++;
	}
}

double	absolute(double x, double y)
{
	return (x * x + y * y);
}
