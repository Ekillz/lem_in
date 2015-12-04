/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 13:37:36 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/04 14:22:56 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
		printf("line: %s, link: %s\n", tmp->line, ant->path->links[i]->name);
		if (ft_strequ(tmp->line, ant->path->links[i]->name))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
