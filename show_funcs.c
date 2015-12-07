/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:21:00 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/07 17:15:44 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	show_map(t_map *map)
{
	t_map *tmp;

	tmp = map;
	while (map)
	{
		ft_putendl(map->line);
		map = map->next;
	}
	ft_putchar('\n');
}

void	show_moves(int i, const char *name)
{
	ft_putchar('L');
	ft_putnbr(i + 1);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}
