/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:06:49 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/04 15:29:11 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_last_path(t_ant *ant, int *weight_total, int *sorted_tab)
{
	int i;
	int	e;

	e = 0;
	i = 0;
	while (weight_total[i])
	{
		if (weight_total[i] == sorted_tab[e])
		{
				printf("het: %d\n", sorted_tab[e]);

			if (compare_last_path(ant, i) >= 0) // problelem cest que tu check que si il existe et du coup ca renvoie 0 mais ca check pas si cest le plus petit
			{
				printf("\n\n\n%d      %d\n\n\n", weight_total[i], sorted_tab[e]);
				free(weight_total);
				return (i);
			}
			else
			{
				if (check_last_path_2(sorted_tab, &e, &i) == -1)
					break;
			}
		}
		i++;
	}
	return (-1);
}

static int	*sort(int *tab, int len)
{
	int i;
	int tmp;
	int	*new_tab;

	i = 0;
	new_tab = malloc(sizeof(int) * len);
	new_tab = tab;
	while (new_tab[i + 1])
	{
		if (new_tab[i] <= new_tab[i + 1])
			i++;
		else
		{
			tmp = new_tab[i + 1];
			new_tab[i + 1] = new_tab[i];
			new_tab[i] = tmp;
			i = 0;
		}
	}
	return (new_tab);
}

static int	get_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	get_weight(t_ant *ant, t_rooms *end_room)
{
	int		*weight_total;
	int		i;
	int		*tmp_tab;

	i = 0;
	weight_total = malloc(sizeof(int) * ant->path->nb_links);
	ft_memset(&weight_total[ant->path->nb_links], 0, sizeof(int));
	while (i < ant->path->nb_links)
	{
		weight_total[i] = get_abs(end_room->x - ant->path->links[i]->x) + get_abs(end_room->y - ant->path->links[i]->y);
		weight_total[i]++;
		printf("current_room : %s, link : %s = 	%d\n", ant->path->name, ant->path->links[i]->name, weight_total[i]);
		i++;
	}
	tmp_tab = sort(weight_total, ant->path->nb_links);
	return (check_last_path(ant, weight_total, tmp_tab));
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
		if ((weight_return = get_weight(ant, end)) >= 0)
		{
			ft_lstinsert(ant->last_path, create_node(ant->path->name, "t_map"), "t_map");
			ant->path = ant->path->links[weight_return];
		}
		//-------------------------------------------//
		if (ft_strequ(ant->path->name, end->name))
			break ;
	}
	printf("Found my way\n");
	// SI temps regler le soucis du premier element NULL, mais pas besoin encore ca marche sans //
}
