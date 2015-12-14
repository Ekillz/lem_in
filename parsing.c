/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 13:10:34 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/14 14:27:19 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		room_exist(t_rooms *rooms, const char *name)
{
	t_rooms *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	recursive_check_path(t_path *path)
{
	int e;

	path->is_end = true;
	e = 0;
	while (path->links[e])
	{
		if (!path->links[e]->is_end)
			recursive_check_path(path->links[e]);
		e++;
	}
}

void	declare_structs(t_data *data)
{
	data->map = malloc(sizeof(t_map));
	data->map->next = NULL;
	data->rooms = malloc(sizeof(t_rooms));
	data->rooms->next = NULL;
	data->links = malloc(sizeof(t_links));
	data->links->next = NULL;
	data->miss_start = true;
	data->miss_end = true;
	data->miss_room = true;
}

int		get_count_room_links(char *line, bool *miss_room, t_rooms *rooms, t_links *links)
{
	char	**datas;
	int		verbose;

	verbose = 0;
	if (line[0] != '#')
	{
		datas = ft_strsplit(line, ' ');
		if (!datas[0] || !datas[1] || !datas[2] ||
				!ft_strequ(ft_itoa(ft_atoi(datas[1])), datas[1]) ||
				!ft_strequ(ft_itoa(ft_atoi(datas[2])), datas[2]))
		{
			verbose++;
		}
		else
		{
			ft_lstinsert(rooms, create_node(datas,"t_rooms"), "t_rooms");
			*miss_room = false;
		}
		ft_freetab(datas);
		datas = ft_strsplit(line, '-');
		if (!datas[0] || !datas[1] || datas[2])
			verbose++;
		else
			ft_lstinsert(links, create_node(datas, "t_links"), "t_links");
		ft_freetab(datas);
		if (verbose == 2)
			return (-1);
	}
	return (0);
}
