/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:50:27 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/01 14:31:14 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	lst_len(t_rooms *rooms)
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

void		link_rooms(t_data *data)
{
	int		list_len;
	int		i;

	i = 0;
	list_len = lst_len(data->rooms);
	data->paths = malloc(sizeof(t_path *) * list_len);
	while (i < list_len)
	{
		data->paths[i] = malloc(sizeof(t_paths *));
		get_links(data->rooms, data->links, &data->paths[i]->nb_links)
	}	
}
