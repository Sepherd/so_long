/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:31:22 by arecce            #+#    #+#             */
/*   Updated: 2022/11/09 15:37:13 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_pos(t_d *d)
{
	d->p.pos_y = 0;
	while (d->p.pos_y < d->h)
	{
		d->p.pos_x = 0;
		while (d->p.pos_x < d->w)
		{
			if (d->map[d->p.pos_y][d->p.pos_x] == 'P')
				return ;
			d->p.pos_x++;
		}
		d->p.pos_y++;
	}
}

void	e_pos(t_d *d)
{
	d->e.pos_y = 0;
	while (d->e.pos_y < d->h)
	{
		d->e.pos_x = 0;
		while (d->e.pos_x < d->w)
		{
			if (d->map[d->e.pos_y][d->e.pos_x] == 'E')
				return ;
			d->e.pos_x++;
		}
		d->e.pos_y++;
	}
	d->e.pos_x = d->e.pos_x;
	d->e.pos_y = d->e.pos_y;
}

int	total_count(t_d *d, char t)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (y < d->h)
	{
		x = 0;
		while (x < d->w)
		{
			if (d->map[y][x] == t)
				i++;
			x++;
		}
	y++;
	}
	return (i);
}

void	close_game(t_d *d)
{
	mlx_destroy_window(d->mlx, d->win);
	map_free(d);
	exit(0);
}
