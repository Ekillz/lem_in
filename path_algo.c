/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:06:49 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/02 18:00:16 by emammadz         ###   ########.fr       */
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

static int	get_weight(t_path *ant, t_rooms *end_room)
{
	int		*weight_total;
	int		i;
	int		*tmp_tab;

	i = 0;
	weight_total = malloc(sizeof(int) * ant->nb_links);
	ft_memset(&weight_total[ant->nb_links], 0, sizeof(int));
	while (i < ant->nb_links)
	{
		weight_total[i] = get_abs(end_room->x - ant->links[i]->x) + get_abs(end_room->y - ant->links[i]->y);
		weight_total[i]++;
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

void		find_path(t_rooms *start, t_rooms *end, t_ant **ants)
{
	t_ant	*ant;
	int		weight_return;

	(void)start;
	ant = ants[0];
	ant->last_path = malloc(sizeof(t_map));
	ant->last_path->next = NULL;
	//ant->last_path = ant->last_path->next;
	while (1)
	{
		//ant->path->is_free = false;
		// if they move do the 2 following instructs // 
		if ((weight_return = get_weight(ant->path, end)) >= 0)
			ft_lstinsert(ant->last_path, create_node(ant->path->name, "t_map"), "t_map");
			ant->path = ant->path->links[weight_return];
		//-------------------------------------------//
		if (ft_strequ(ant->path->name, end->name))
			break ;
	}
	printf("Found my way\n");
	// SI temps regler le soucis du premier element NULL, mais pas besoin encore ca marche sans //
}
