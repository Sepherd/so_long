/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:13:21 by arecce            #+#    #+#             */
/*   Updated: 2022/11/10 18:04:44 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_an(t_d *d)
{
	int		c;
	time_t	t;

	t = time(&t);
	c = 65;
	if (t % 8 == 0)
	{
		d->exit = mlx_xpm_file_to_image(d->e.mlx, "img/x1.xpm", &c, &c);
		mlx_put_image_to_window(d->e.mlx, d->win, d->floor, \
			d->e.pos_x * 64, d->e.pos_y * 64);
		mlx_put_image_to_window(d->e.mlx, d->win, d->exit, \
			d->e.pos_x * 64, d->e.pos_y * 64);
	}
	else
	{
		d->exit = mlx_xpm_file_to_image(d->e.mlx, "img/x2.xpm", &c, &c);
		mlx_put_image_to_window(d->e.mlx, d->win, d->floor, \
			d->e.pos_x * 64, d->e.pos_y * 64);
		mlx_put_image_to_window(d->e.mlx, d->win, d->exit, \
			d->e.pos_x * 64, d->e.pos_y * 64);
	}
	return (0);
}

void	draw_floor(t_d *d)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < d->h)
	{
		k = 0;
		x = 0;
		while (k < d->w)
		{
			if (d->map[i][k] == '0')
				mlx_put_image_to_window(d->mlx, d->win, d->floor, x, y);
			k++;
			x += 64;
		}
		i++;
		y += 64;
	}
}
