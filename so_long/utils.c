/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:31:22 by arecce            #+#    #+#             */
/*   Updated: 2022/10/28 18:32:18 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_pos(t_data *data)
{
	data->p.pos_y = 0;
	while (data->p.pos_y < data->h)
	{
		data->p.pos_x = 0;
		while (data->p.pos_x < data->w)
		{
			if (data->map[data->p.pos_y][data->p.pos_x] == 'P')
				return ;
			data->p.pos_x++;
		}
		data->p.pos_y++;
	}
}

void	total_clt(t_data *data, char t)
{
	int	x;
	int	y;

	y = 0;
	data->p.clt_tot = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			if (data->map[y][x] == t)
				data->p.clt_tot++;
			x++;
		}
	y++;
	}
}

void	close_game(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	map_free(data);
	exit(0);
}
