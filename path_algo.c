/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:06:49 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/02 14:58:52 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	*sort(int *tab)
{
	int i;
	int tmp;

	i = 0;
	while (tab[i + 1])
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
	}
	return (tab);
}

static int	get_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	get_weight(t_path *ant)
{
	int		*weight_total;
	int		i;
	int		*tmp_tab;

	i = 0;
	weight_total = malloc(sizeof(int) * ant->nb_links);
	memset(&weight_total[ant->nb_links], 0, sizeof(int));
	while (i < ant->nb_links)
	{
		weight_total[i] = get_abs(ant->links[i]->x - ant->x) + get_abs(ant->links[i]->y - ant->y);
		i++;
	}
	tmp_tab = sort(weight_total);
	i = 0;
	while (weight_total[i])
	{
		if (weight_total[i] == tmp_tab[0])
		{
			free(weight_total);
			return (i);
		}
		i++;
	}
	return (-1);
}

void		find_path(t_rooms *start, t_rooms *end, t_path **paths, t_ant **ants)
{
	t_ant	*ant;

	(void)paths;
	(void)start;
	(void)end;
	ant = ants[0];
	while (1)
	{
		ant->path = paths[get_weight(ant->path)];
		// fair liste insert 
		if (ft_strequ(ant->path->name, end->name))
			break ;
	}
	printf("Found my way\n");
}
