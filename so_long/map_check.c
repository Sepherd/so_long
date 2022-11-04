/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:18:03 by arecce            #+#    #+#             */
/*   Updated: 2022/11/04 16:11:47 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_dim(char **av, t_d *d)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit(0);
	d->h = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		d->h++;
	}
	d->w = 0;
	close(fd);
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line[d->w] != '\n')
		d->w++;
	free(line);
	close(fd);
}

void	square(t_d *d)
{
	if (d->w == d->h)
		map_error();
}

void	len_check(char **av, t_d *d)
{
	int		i;
	int		k;
	int		fd;
	char	*line;

	i = 0;
	get_dim(av, d);
	fd = open(av[1], O_RDONLY);
	while (i < d->h)
	{
		k = 0;
		line = get_next_line(fd);
		while (line[k] != '\n' && line[k] != '\0')
			k++;
		if (k != d->w)
			map_error();
		free(line);
		i++;
	}
	close(fd);
}

void	line_check(char **av, t_d *d)
{
	int		i;
	int		k;
	int		fd;
	char	*line;

	i = 0;
	len_check(av, d);
	fd = open(av[1], O_RDONLY);
	while (i < d->h)
	{
		k = 0;
		line = get_next_line(fd);
		while (line[k] != '\n' && line[k] != '\0')
		{
			check_utils(d, i, k, line);
			k++;
		}
		i++;
		free(line);
	}
	close(fd);
}

void	get_map(char **av, t_d *d)
{
	int	i;
	int	fd;

	i = 0;
	line_check(av, d);
	square(d);
	d->map = malloc(sizeof(char **) * d->h);
	fd = open(av[1], O_RDONLY);
	while (i < d->h)
	{
		d->map[i] = get_next_line(fd);
		i++;
	}
}
