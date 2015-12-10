/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:21:00 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/09 14:44:24 by emammadz         ###   ########.fr       */
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

void	show_moves(int i, const char *name, int fd)
{
	char *move;
	
	move = 0;
	move = ft_strjoin(ft_strjoin(ft_strjoin(move, "L"), ft_itoa(i + 1)), "-");
	move = ft_strjoin(ft_strjoin(move, name), " ");
	ft_putstr(move);
	ft_putstr_fd(move,fd);
	free(move);
}
