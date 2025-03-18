/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:35:45 by azahid            #+#    #+#             */
/*   Updated: 2025/03/18 03:32:27 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <unistd.h>

void	setinit(t_screen *scr, char **av, int flag)
{
	scr->av = av;
	scr->value.xmax = 2.0;
	scr->value.ymax = 2.0;
	scr->value.xmin = -2.0;
	scr->value.ymin = -2.0;
	scr->flag = flag;
}

int	drawchanges(t_screen *scr, int ac, char **av)
{
	if (ft_strncmp(scr->av[1], "julia", 6) == 0 && ac == 4)
	{
		setinit(scr, av, 1);
		drawjulia(*scr);
		return (1);
	}
	else if (ft_strncmp(scr->av[1], "mandelbrot_set", 15) == 0 && ac == 2)
	{
		setinit(scr, av, 2);
		drawmandelbrotset(*scr);
		return (2);
	}
	return (-1);
}

void	handleexeptions(int ac, char *av[])
{
	if (ac < 2 || (ft_strncmp("julia", av[1], 6) && ft_strncmp(av[1],
				"mandelbrot_set", 15)))
	{
		write(2, "usage : ./fractol julia [+/-xx.xx] [+/-xx.xx]\n", 46);
		write(2, "usage : ./fractol mandelbrot_set\n", 34);
		exit(1);
	}
	if (!ft_strncmp(av[1], "julia", 6))
	{
		if (ac != 4 || checkerav(av))
		{
			write(2, "usage : ./fractol julia [+/-xx.xx] [+/-xx.xx]\n", 46);
			exit(1);
		}
	}
	else if (!ft_strncmp(av[1], "mandelbrot_set", 15))
	{
		if (ac != 2)
		{
			write(2, "usage : ./fractol mandelbrot_set\n", 34);
			exit(1);
		}
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
