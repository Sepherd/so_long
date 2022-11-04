/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:53:15 by arecce            #+#    #+#             */
/*   Updated: 2022/11/04 15:55:26 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_d *d)
{
	int	c;

	c = 65;
	d->floor = mlx_xpm_file_to_image(d->mlx_ptr, "img/0.xpm", &c, &c);
	d->wall = mlx_xpm_file_to_image(d->mlx_ptr, "img/1.xpm", &c, &c);
	d->clt = mlx_xpm_file_to_image(d->mlx_ptr, "img/c.xpm", &c, &c);
	d->pg = mlx_xpm_file_to_image(d->mlx_ptr, "img/pf0.xpm", &c, &c);
	d->exit = mlx_xpm_file_to_image(d->mlx_ptr, "img/x0.xpm", &c, &c);
	d->enemy = mlx_xpm_file_to_image(d->mlx_ptr, "img/ef0.xpm", &c, &c);
}

void	control_total(t_d *d)
{
	d->p.clt_tot = total_count(d, 'C');
	d->p.ex_tot = total_count(d, 'E');
	d->p.pg_tot = total_count(d, 'P');
	if (d->p.ex_tot != 1 || d->p.pg_tot != 1 || d->p.clt_tot < 1)
		close_game(d);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_ber(char **av)
{
	int		i;
	int		k;
	char	temp[5];

	i = ft_strlen(av[1]) - 4;
	k = 0;
	while (av[1][i])
	{
		temp[k++] = av[1][i++];
	}
	temp[k] = '\0';
	if (!ft_strcmp(temp, ".ber"))
	{
		ft_printf("\033[1;31mNome mappa errato!\n\033[1;0m");
		exit(0);
	}
}
