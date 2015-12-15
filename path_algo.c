/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:06:49 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/15 15:52:47 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_last_path(t_ant *ant, int *weight, int *tab, t_rooms *end)
{
	int i;
	int	e;

	e = 0;
	i = -1;
	if (ant->is_out)
		return (-1);
	while (weight[++i])
	{
		if (weight[i] == tab[e])
		{
			if (compare_last_path(ant, i) >= 0 && (ant->path->links[i]->is_free
						|| ft_strequ(ant->path->links[i]->name, end->name)))
			{
				free(weight);
				return (i);
			}
			else
			{
				if (check_last_path_2(tab, &e, &i) == -1)
					break ;
			}
		}
	}
	return (-1);
}

static int	*sort(int *tab, int len)
{
	int i;
	int tmp;
	int	*new_tab;

	i = -1;
	new_tab = malloc(sizeof(int) * len);
	ft_memset(&new_tab[len], 0, sizeof(int));
	while (++i < len)
		new_tab[i] = tab[i];
	i = 0;
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
		weight_total[i] = get_abs(end_room->x - ant->path->links[i]->x) +
			get_abs(end_room->y - ant->path->links[i]->y);
		weight_total[i] += 2;
		if (!ant->path->links[i]->is_free)
			weight_total[i] += 1000000;
		if (ft_strequ(ant->path->links[i]->name, end_room->name))
			weight_total[i] = 1;
		i++;
	}
	tmp_tab = sort(weight_total, ant->path->nb_links);
	return (check_last_path(ant, weight_total, tmp_tab, end_room));
}

void		find_path(t_rooms *end, t_ant **ants, int nb_ants, t_rooms *start)
{
	int		weight_return;
	int		i;
	int		out;
	int		fd;

	fd = open("/nfs/zfs-student-3/users/emammadz/unity_file/file.txt",
			O_RDWR | O_APPEND);
	out = 0;
	alloc_last_path(ants, nb_ants);
	while (out != nb_ants)
	{
		i = -1;
		while (++i < nb_ants)
		{
			if ((weight_return = get_weight(ants[i], end)) >= 0)
			{
				change_ant_path(ants[i], weight_return, start);
				show_moves(i, ants[i]->path->name, fd);
			}
			check_ant_finish(ants[i], end->name, &out);
		}
		ft_putchar('\n');
		ft_putchar_fd('\n', fd);
	}
	close(fd);
}
