/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:50:27 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/02 13:34:48 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_path			*get_room_by_name(t_path **all_paths, const char *name)
{
	int		i;

	i = 0;
	while (all_paths[i])
	{
		if (ft_strequ(all_paths[i]->name, name))
			return (all_paths[i]);
		i++;
	}
	return (NULL);
}

static void		link_path_rooms(t_path **all_paths, t_links *links, t_path *path)
{
	t_links *tmp_links;
	int		i;

	i = 0;
	tmp_links = links;
	while (tmp_links)
	{
		if (ft_strequ(tmp_links->a, path->name))
		{
			path->links[i] = get_room_by_name(all_paths, tmp_links->b);
			i++;
		}
		else if (ft_strequ(tmp_links->b, path->name))
		{
			path->links[i] = get_room_by_name(all_paths, tmp_links->a);
			i++;
		}
		tmp_links = tmp_links->next;
	}

}

static void		get_links(t_rooms *room, t_links *links, int *nb_links, t_path *path)
{
	t_links	*tmp_link;

	tmp_link = links;
	*nb_links = 0;
	path->name = room->name;
	path->x = room->x;
	path->y = room->y;
	path->is_free = true;
	while (tmp_link)
	{
		if (ft_strequ(tmp_link->a, room->name) || ft_strequ(tmp_link->b, room->name))
			(*nb_links)++;
		tmp_link = tmp_link->next;
	}
}

static int		lst_len(t_rooms *rooms)
{
	t_rooms *tmp;
	int		i;

	i = 0;
	tmp = rooms;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void			link_rooms(t_data *data)
{
	int		list_len;
	int		i;
	t_rooms	*tmp_room;

	i = 0;
	tmp_room = data->rooms;
	list_len = lst_len(data->rooms);
	data->paths = malloc(sizeof(t_path) * list_len);
	while (i < list_len)
	{
		data->paths[i] = malloc(sizeof(t_path));
		get_links(tmp_room, data->links, &data->paths[i]->nb_links, data->paths[i]);
		tmp_room = tmp_room->next;
		i++;
	}
	i = 0;
	while (i < list_len)
	{
		data->paths[i]->links = malloc(sizeof(t_path) * data->paths[i]->nb_links);
		link_path_rooms(data->paths, data->links, data->paths[i]);
		i++;
	}
}
