/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:18:03 by arecce            #+#    #+#             */
/*   Updated: 2022/10/28 14:43:51 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_dim(char **av, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	data->h = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		data->h++;
	}
	data->w = 0;
	close(fd);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line[data->w] != '\n')
		data->w++;
	free(line);
	close(fd);
}

void	len_check(char **av, t_data *data)
{
	int		i;
	int		k;
	int		fd;
	char	*line;

	i = 0;
	get_dim(av, data);
	fd = open(av[1], O_RDONLY);
	while (i < data->h)
	{
		k = 0;
		line = get_next_line(fd);
		while (line[k] != '\n' && line[k] != '\0')
			k++;
		if (k != data->w)
			map_error();
		free(line);
		i++;
	}
	close(fd);
}

void	line_check(char **av, t_data *data)
{
	int		i;
	int		k;
	int		fd;
	char	*line;

	i = 0;
	len_check(av, data);
	fd = open(av[1], O_RDONLY);
	while (i < data->h)
	{
		k = 0;
		line = get_next_line(fd);
		while (line[k] != '\n' && line[k] != '\0')
		{
			if ((i == 0 || i == data->h - 1) && line[k] != '1')
				map_error();
			else if (i != 0 && i != data->h - 1)
			{
				if ((k == 0 || k == data->w - 1) && line[k] != '1')
					map_error();
				else if ((k > 0 && k < data->w - 1) && (line[k] != 'C' && line[k] != '0' && line[k] != 'P' && line[k] != 'E' && line[k] != '1' && line[k] != 'X'))
					map_error();
			}
			k++;
		}
		i++;
		free(line);
	}
	close(fd);
}

void	get_map(char **av, t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	line_check(av, data);
	map_memory(data);
	fd = open(av[1], O_RDONLY);
	while (i < data->h)
	{
		data->map[i] = get_next_line(fd);
		i++;
	}
	/* i = 0;
	while (i < data->h)
	{
		ft_printf("%s", data->map[i]);
		i++;
	} */
}
