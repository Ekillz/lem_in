/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:06:53 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/15 17:29:19 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_ants(char *line, int *nb_ants)
{
	int ant;

	ant = ft_atoi(line);
	if (ant <= 0)
	{
		ft_putendl("Not enough ants or not digit");
		return (-1);
	}
	*nb_ants = ant;
	return (0);
}

static int	open_file(t_data *data)
{
	char	*line;
	int		argument;

	argument = 0;
	get_next_line(0, &line);
	ft_lstinsert(data->map, create_node(line, "t_map"), "t_map");
	if (get_ants(line, &data->nb_ants) == -1)
		return (-1);
	read_map_loop(data, line, argument);
	data->map = data->map->next;
	ft_lstreverse(&data->map);
	data->links = data->links->next;
	data->rooms = data->rooms->next;
	show_map(data->map);
	if (check_missing_data(data->miss_start,
				data->miss_end, data->miss_room) == -1)
		return (-1);
	return (0);
}

int			main(void)
{
	t_data data;

	declare_structs(&data);
	if (open_file(&data) == -1)
		exit(-1);
	link_rooms(&data);
	assign_ants(&data);
	write_file(&data);
	recursive_check_path(get_room_by_name(data.paths, data.start_room->name));
	if (!(get_room_by_name(data.paths, data.end_room->name))->is_end)
		no_path_possible();
	find_path(data.end_room, data.ants, data.nb_ants, data.start_room);
	system("open visual.app");
	return (0);
}
