/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:13:21 by arecce            #+#    #+#             */
/*   Updated: 2022/11/03 17:13:48 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_an(t_data *data)
{
	int		c = 65;
	clock_t	t = clock() / 500000;

	if (t % 8)
	{
		data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/x2.xpm", &c, &c);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->e.pos_x * 64, data->e.pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, data->e.pos_x * 64, data->e.pos_y * 64);
	}
	else
	{
		data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "img/x1.xpm", &c, &c);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->e.pos_x * 64, data->e.pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit, data->e.pos_x * 64, data->e.pos_y * 64);
	}
	return (0);
}

/* int	enemy_an(t_data *data)
{
	int	c = 65;
	clock_t	t = clock() / 500000;

	
} */

void	pg_an(t_data *data)
{
	int	c = 65;
	clock_t	t = clock() / 500000;

	p_pos(data);
	data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/p0.xpm", &c, &c);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, data->p.pos_x * 64, data->p.pos_y * 64);
	if (t % 2 == 0)
	{
		data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/p1.xpm", &c, &c);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, data->p.pos_x * 64, data->p.pos_y * 64);
	}
	if (t % 3 == 0)
	{
		data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/p2.xpm", &c, &c);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, data->p.pos_x * 64, data->p.pos_y * 64);
	}
	if (t % 4 == 0)
	{
		data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/p3.xpm", &c, &c);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, data->p.pos_x * 64, data->p.pos_y * 64);
	}
	if (t % 5 == 0)
	{
		data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/p4.xpm", &c, &c);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, data->p.pos_x * 64, data->p.pos_y * 64);
	}
	if (t % 6 == 0)
	{
		data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/p5.xpm", &c, &c);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, data->p.pos_x * 64, data->p.pos_y * 64);
	}
	if (t % 7 == 0)
	{
		data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/p6.xpm", &c, &c);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, data->p.pos_x * 64, data->p.pos_y * 64);
	}
	/* data->pg = mlx_xpm_file_to_image(data->mlx_ptr, "img/pf0.xpm", &c, &c);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor, data->p.pos_x * 64, data->p.pos_y * 64);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->pg, data->p.pos_x * 64, data->p.pos_y * 64); */
}
