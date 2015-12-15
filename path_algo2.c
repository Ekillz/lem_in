/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:37:36 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/15 15:54:05 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_ant_finish(t_ant *ant, char *name, int *out)
{
	if (ft_strequ(ant->path->name, name) && !ant->is_out)
	{
		ant->is_out = true;
		(*out)++;
	}
}

void	change_ant_path(t_ant *ant, int weight_return, t_rooms *start)
{
	if (!ft_strequ(ant->path->name, start->name))
		ant->path->is_free = true;
	ft_lstinsert(ant->last_path,
			create_node(ant->path->name, "t_map"), "t_map");
	ant->path = ant->path->links[weight_return];
	ant->path->is_free = false;
}

void	alloc_last_path(t_ant **ants, int nb_ants)
{
	int i;

	i = 0;
	while (i < nb_ants)
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
		(*i) = -1;
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
