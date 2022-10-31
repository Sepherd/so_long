/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:02:18 by arecce            #+#    #+#             */
/*   Updated: 2022/10/31 18:22:09 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	ft_printf("Error\nManco una mappa sai disegnare...\n");
	exit(0);
}

void	map_memory(t_data *data)
{
	// int	i;

	// i = 0;
	data->map = malloc(sizeof(char **) * data->h);
	// while (i < data->h)
	// {
	// 	data->map[i] = malloc(sizeof(char *) * data->w + 1);
	// 	i++;
	// }
}

void	map_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->h)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	draw_all(t_data *data)
{
	draw_map(data);
	draw_clt(data);
	draw_exit(data);
	draw_pg(data);
	draw_enemy(data);
}

/* int	exit_loop(t_data *data)
{
	int		c = 65;
	clock_t	t = clock() / 500000;

	if (t % 6)
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
	mlx_destroy_image(data->mlx_ptr, data->exit);
	return (0);
} */
