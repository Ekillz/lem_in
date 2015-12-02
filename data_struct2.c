/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:16:58 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/02 17:36:43 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	assign_ants(t_data *data)
{
	int		i;
	t_path *start_room;

	i = 0;
	start_room = get_room_by_name(data->paths, data->start_room->name);
	data->ants = malloc(sizeof(t_ant) * data->nb_ants);
	while (i < data->nb_ants)
	{
		data->ants[i] = malloc(sizeof(t_ant));
		data->ants[i]->path = start_room;
		i++;
	}
}
