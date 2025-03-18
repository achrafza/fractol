/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:35:45 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 00:56:34 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <string.h>
#include <unistd.h>

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	closeit(t_screen *scr)
{
	mlx_destroy_image(scr->vars.mlx, scr->img.img);
	mlx_clear_window(scr->vars.mlx, scr->vars.win);
	mlx_destroy_window(scr->vars.mlx, scr->vars.win);
	exit(0);
	return (0);
}

void	setinit(t_screen *scr, char **av, int flag)
{
	scr->av = av;
	scr->value.xmax = 2.0;
	scr->value.ymax = 2.0;
	scr->value.xmin = -2.0;
	scr->value.ymin = -2.0;
	scr->flag = flag;
}

static int	point(char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '.')
			c++;
		i++;
	}
	return (c);
}

static int	checker(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (!s[i])
		return (1);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (1);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] == '.' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
		i++;
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i])
		return (1);
	return (0);
}

int	checkerav(char **av)
{
	return ((checker(av[2]) || checker(av[3])) || ((point(av[2]) > 1)
			|| (point(av[3]) > 1)));
}

int	drawchanges(t_screen *scr, int ac, char **av)
{
	if (strcmp(scr->av[1], "julia") == 0 && ac == 4)
	{
		setinit(scr, av, 1);
		drawjulia(*scr);
		return (1);
	}
	else if (strcmp(scr->av[1], "mandelbrot_set") == 0 && ac == 2)
	{
		setinit(scr, av, 2);
		drawmandelbrotset(*scr);
		return (2);
	}

	return (-1);
}

void	handleexeptions(int ac, char *av[])
{
	if (ac < 2)
	{
		write(2, "usage : ./fractol julia [+/-xx.xx] [+/-xx.xx]\n", 46);
		write(2, "usage : ./fractol mandelbrot_set\n", 34);
		exit(1);
	}
	if (!strcmp(av[1], "julia"))
	{
		if (ac != 4 || checkerav(av))
		{
			write(2, "usage : ./fractol julia [+/-xx.xx] [+/-xx.xx]\n", 46);
			exit(1);
		}
	}
	else if (!strcmp(av[1], "mandelbrot_set"))
	{
		if (ac != 2)
		{
			write(2, "usage : ./fractol mandelbrot_set\n", 34);
			exit(1);
		}
	}
	else if (strcmp("julia", av[1]) && strcmp(av[1], "mandelbrot_set"))
	{
		write(2, "usage : ./fractol julia [+/-xx.xx] [+/-xx.xx]\n", 46);
		write(2, "usage : ./fractol mandelbrot_set\n", 34);
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	t_screen	screen;

	handleexeptions(ac, av);
	screen.vars.mlx = mlx_init();
  if (!screen.vars.mlx)
    exit(1);
	screen.av = av;
	screen.vars.win = mlx_new_window(screen.vars.mlx, WIDTH, HEIGHT, "fractol");
  if (!screen.vars.win)
    exit(1);
	screen.img.img = mlx_new_image(screen.vars.mlx, WIDTH, HEIGHT);
  if (!screen.img.img)
    exit(1);
	screen.img.addr = mlx_get_data_addr(screen.img.img,
			&(screen.img.bits_per_pixel), &(screen.img.line_length),
			&(screen.img.endian));
  if (!screen.img.addr)
    exit(1);
	drawchanges(&screen, ac, av);
	mlx_put_image_to_window(screen.vars.mlx, screen.vars.win, screen.img.img, 0,
		0);
	mlx_hook(screen.vars.win, 17, 0, closeit, &screen);
	mlx_key_hook(screen.vars.win, key_listener, &screen);
	mlx_mouse_hook(screen.vars.win, mouse_listener, &screen);
	mlx_loop(screen.vars.mlx);
}
