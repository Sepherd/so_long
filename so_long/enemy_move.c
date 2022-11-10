/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:39:57 by arecce            #+#    #+#             */
/*   Updated: 2022/11/10 18:44:32 by arecce           ###   ########.fr       */
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
	if (d->m_move > 0)
	{
		if (d->m_move % 7 == 0)
			enemy_back(d);
		else if (d->m_move % 12 == 0)
			enemy_front(d);
		else if (d->m_move % 9 == 0)
			enemy_right(d);
		else if (d->m_move % 16 == 0)
			enemy_left(d);
	}
}
