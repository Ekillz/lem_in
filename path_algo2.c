/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:37:36 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/04 17:22:07 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	alloc_last_path(t_ant **ants)
{
	int i;

	i = 0;
	while (ants[i])
	{
		ants[i]->last_path = malloc(sizeof(t_map));
		ants[i]->last_path->next = NULL;
		i++;
	}
}

int		check_last_path_2(int *sorted_tab, int *e, int *i)
{
	if (sorted_tab[*e + 1])
	{
		(*e)++;
		(*i) = 0;
		return (1);
	}
	return (-1);
}

int		compare_last_path(t_ant *ant, int i)
{
	t_map *tmp;

	tmp = ant->last_path;
	while (tmp)
	{
		if (ft_strequ(tmp->line, ant->path->links[i]->name))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
