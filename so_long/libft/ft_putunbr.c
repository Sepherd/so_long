/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arecce <arecce@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:31:42 by arecce            #+#    #+#             */
/*   Updated: 2022/09/09 16:41:55 by arecce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_unconvert(unsigned int nb)
{
	if (nb > 0)
	{
		ft_unconvert(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

int	ft_putunbr(unsigned int nb)
{
	int			len_print;
	int			print;

	len_print = ft_numlen(nb);
	print = 0;
	if (nb == 0)
		ft_putchar('0');
	else
	{
		ft_unconvert(nb);
	}
	return (len_print);
}
