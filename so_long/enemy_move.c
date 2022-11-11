/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:39:57 by arecce            #+#    #+#             */
/*   Updated: 2022/11/11 16:38:06 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	en_pos(t_d *d)
{
	d->e.en_y = 0;
	while (d->e.en_y < d->h)
	{
		d->e.en_x = 0;
		while (d->e.en_x < d->w)
		{
			if (d->map[d->e.en_y][d->e.en_x] == 'X')
				en_move(d);
			d->e.en_x++;
		}
		d->e.en_y++;
	}
}

void	en_move(t_d *d)
{
	if (d->m_move % 3 == 0)
	{
		if (d->p.pos_x > d->e.en_x \
			&& (d->map[d->e.en_y][d->e.en_x + 1] == '0' \
			|| d->map[d->e.en_y][d->e.en_x + 1] == 'P'))
			enemy_right(d);
		else if (d->p.pos_x < d->e.en_x \
				&& (d->map[d->e.en_y][d->e.en_x - 1] == '0' \
				|| d->map[d->e.en_y][d->e.en_x - 1] == 'P'))
			enemy_left(d);
		else if (d->p.pos_y > d->e.en_y \
				&& (d->map[d->e.en_y + 1][d->e.en_x] == '0' \
				|| d->map[d->e.en_y + 1][d->e.en_x] == 'P'))
			enemy_front(d);
		else if (d->p.pos_y < d->e.en_y \
				&& (d->map[d->e.en_y - 1][d->e.en_x] == '0' \
				|| d->map[d->e.en_y - 1][d->e.en_x] == 'P'))
			enemy_back(d);
	}
}
