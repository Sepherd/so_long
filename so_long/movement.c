/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:07:03 by arecce            #+#    #+#             */
/*   Updated: 2022/10/31 19:13:20 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	front_move(t_data *data)
{
	int	c;

	c = 65;
	p_pos(data);
	data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/pf0.xpm", &c, &c);
	if (data->map[data->p.pos_y + 1][data->p.pos_x] == '0' \
		|| data->map[data->p.pos_y + 1][data->p.pos_x] == 'C')
	{
		data->map[data->p.pos_y][data->p.pos_x] = '0';
		data->map[data->p.pos_y + 1][data->p.pos_x] = 'P';
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
		// draw_pg(data);
		// mlx_clear_window(data->mlx_ptr, data->win_ptr);
		// draw_map(data);
	}
	else if (data->map[data->p.pos_y + 1][data->p.pos_x] == 'X')
	{
		ft_printf("HAI PERSO!\n");
		close_game(data);
	}
	else if (data->map[data->p.pos_y + 1][data->p.pos_x] == 'E')
		win(data);
}

void	back_move(t_data *data)
{
	int	c;

	c = 65;
	p_pos(data);
	data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/pb0.xpm", &c, &c);
	if (data->map[data->p.pos_y - 1][data->p.pos_x] == '0' \
		|| data->map[data->p.pos_y - 1][data->p.pos_x] == 'C')
	{
		data->map[data->p.pos_y][data->p.pos_x] = '0';
		data->map[data->p.pos_y - 1][data->p.pos_x] = 'P';
		// mlx_clear_window(data->mlx_ptr, data->win_ptr);
		// draw_map(data);
	}
	else if (data->map[data->p.pos_y - 1][data->p.pos_x] == 'X')
	{
		ft_printf("HAI PERSO!\n");
		close_game(data);
	}
	else if (data->map[data->p.pos_y - 1][data->p.pos_x] == 'E')
		win(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
	// draw_pg(data);
}

void	right_move(t_data *data)
{
	int	c;

	c = 65;
	p_pos(data);
	data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/pr0.xpm", &c, &c);
	if (data->map[data->p.pos_y][data->p.pos_x + 1] == '0' \
		|| data->map[data->p.pos_y][data->p.pos_x + 1] == 'C')
	{
		data->map[data->p.pos_y][data->p.pos_x] = '0';
		data->map[data->p.pos_y][data->p.pos_x + 1] = 'P';
		// mlx_clear_window(data->mlx_ptr, data->win_ptr);
		// draw_map(data);
	}
	else if (data->map[data->p.pos_y][data->p.pos_x + 1] == 'X')
	{
		ft_printf("HAI PERSO!\n");
		close_game(data);
	}
	else if (data->map[data->p.pos_y][data->p.pos_x + 1] == 'E')
		win(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
	// draw_pg(data);
}

void	left_move(t_data *data)
{
	int	c;

	c = 65;
	p_pos(data);
	data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/pl0.xpm", &c, &c);
	if (data->map[data->p.pos_y][data->p.pos_x - 1] == '0' \
		|| data->map[data->p.pos_y][data->p.pos_x - 1] == 'C')
	{
		data->map[data->p.pos_y][data->p.pos_x] = '0';
		data->map[data->p.pos_y][data->p.pos_x - 1] = 'P';
		// mlx_clear_window(data->mlx_ptr, data->win_ptr);
		// draw_map(data);
	}
	else if (data->map[data->p.pos_y][data->p.pos_x - 1] == 'X')
	{
		ft_printf("HAI PERSO!\n");
		close_game(data);
	}
	else if (data->map[data->p.pos_y][data->p.pos_x - 1] == 'E')
		win(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
	// draw_pg(data);
}

void	win(t_data *data)
{
	data->p.clt_tot = total_count(data, 'C');
	if (data->p.clt_tot == 0)
	{
		ft_printf("HAI VINTO!\n");
		close_game(data);
	}
}
