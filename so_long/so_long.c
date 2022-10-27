/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:39:26 by arecce            #+#    #+#             */
/*   Updated: 2022/10/27 20:01:09 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//keycode		key
//	1			s
//	0			a
//	2			d
//	13			w
//	53			esc
//	49			space

int	closes(int keycode, t_data *data)
{
	// ft_printf("%d\n", keycode);
	char	*moves;	
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		map_free(data);
		exit(0);
	}
	else if (keycode == 1)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 50, 60);
		data->m_move++;
	}
	else if (keycode == 0)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 40, 50);
		data->m_move++;
	}
	else if (keycode == 2)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 60, 50);
		data->m_move++;
	}
	else if (keycode == 13)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 50, 40);
		data->m_move++;
	}
	else if (keycode == 49)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 50, 50);
		data->m_move++;
	}
	moves = ft_itoa(data->m_move);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 16, 16, 0xFFFFFF, moves);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	int	c = 32;
	data.m_move = 0;
	get_map(av, &data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 320, 320, "Dragon Ball M");
	draw_map(&data);
	data.img = mlx_xpm_file_to_image(data.mlx_ptr, "img/pf0.xpm", &c, &c);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 96, 96);
	mlx_hook(data.win_ptr, 2, (1L << 0), closes, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
