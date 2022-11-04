/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:13:21 by arecce            #+#    #+#             */
/*   Updated: 2022/11/04 15:59:22 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_an(t_d *d)
{
	int		c;
	clock_t	t;

	c = 65;
	t = clock() / 500000;
	if (t % 8)
	{
		d->exit = mlx_xpm_file_to_image(d->e.mlx_ptr, "img/x2.xpm", &c, &c);
		mlx_put_image_to_window(d->e.mlx_ptr, d->win_ptr, d->floor, \
			d->e.pos_x * 64, d->e.pos_y * 64);
		mlx_put_image_to_window(d->e.mlx_ptr, d->win_ptr, d->exit, \
			d->e.pos_x * 64, d->e.pos_y * 64);
	}
	else
	{
		d->exit = mlx_xpm_file_to_image(d->e.mlx_ptr, "img/x1.xpm", &c, &c);
		mlx_put_image_to_window(d->e.mlx_ptr, d->win_ptr, d->floor, \
			d->e.pos_x * 64, d->e.pos_y * 64);
		mlx_put_image_to_window(d->e.mlx_ptr, d->win_ptr, d->exit, \
			d->e.pos_x * 64, d->e.pos_y * 64);
	}
	return (0);
}
