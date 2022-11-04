/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:02:18 by arecce            #+#    #+#             */
/*   Updated: 2022/11/04 14:37:28 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	ft_printf("\033[1;31mError!\nManco una mappa sai disegnare...\n\033[1;0m");
	exit(0);
}

void	check_utils(t_d *d, int i, int k, char *line)
{
	if ((i == 0 || i == d->h - 1) && line[k] != '1')
		map_error();
	else if (i != 0 && i != d->h - 1)
	{
		if ((k == 0 || k == d->w - 1) && line[k] != '1')
			map_error();
		else if ((k > 0 && k < d->w - 1) && (line[k] != 'C' && line[k] != '0' \
			&& line[k] != 'P' && line[k] != 'E' && line[k] != '1' \
				&& line[k] != 'X'))
			map_error();
	}
}

void	map_free(t_d *d)
{
	int	i;

	i = 0;
	while (i < d->h)
	{
		free(d->map[i]);
		i++;
	}
	free(d->map);
}

void	draw_all(t_d *d)
{
	draw_map(d);
	draw_clt(d);
	draw_exit(d);
	draw_pg(d);
	draw_enemy(d);
}
