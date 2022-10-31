/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:53:15 by arecce            #+#    #+#             */
/*   Updated: 2022/10/31 19:41:33 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_data *data)
{
	int	c;

	c = 65;
	data->floor = mlx_xpm_file_to_image(data->mlx_ptr, "img/0.xpm", &c, &c);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "img/1.xpm", &c, &c);
	data->clt = mlx_xpm_file_to_image(data->mlx_ptr, "img/c.xpm", &c, &c);
	data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/pf0.xpm", &c, &c);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/x0.xpm", &c, &c);
	data->enemy = mlx_xpm_file_to_image(data->mlx_ptr, "img/ef0.xpm", &c, &c);
}

void	control_total(t_data *data)
{
	data->p.clt_tot = total_count(data, 'C');
	data->p.ex_tot = total_count(data, 'E');
	data->p.pg_tot = total_count(data, 'P');
	if (data->p.ex_tot != 1 || data->p.pg_tot != 1 || data->p.clt_tot < 1)
		close_game(data);
}

void	check_ber(char **av)
{
	
}
