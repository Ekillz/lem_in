/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:06:53 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/04 17:14:41 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int get_start_end_room(char *line, t_rooms **start_room, t_rooms **end_room, int which)
{
	char	**datas;

	datas = ft_strsplit(line, ' ');
	if (!datas[0] || !datas[1] || !datas[2] ||
			ft_isdigit(ft_atoi(datas[1])) || ft_isdigit(ft_atoi(datas[2])))
	{
		ft_freetab(datas);
		return (-1);
	}
	if (which == 0)
	{
		*start_room = malloc(sizeof(t_rooms));
		(*start_room)->name = ft_strdup(datas[0]);
		(*start_room)->x = ft_atoi(datas[1]);
		(*start_room)->y = ft_atoi(datas[2]);
	}
	else
	{
		*end_room = malloc(sizeof(t_rooms));
		(*end_room)->name = ft_strdup(datas[0]);
		(*end_room)->x = ft_atoi(datas[1]);
		(*end_room)->y = ft_atoi(datas[2]);
	}
	ft_freetab(datas);
	return (0);
}

static int check_line(char *line, bool *miss_start, bool *miss_end)
{
	if (ft_strequ("##start", line))
	{
		*miss_start = false;
		return (2);
	}
	else if (ft_strequ("##end", line))
	{
		*miss_end = false;
		return (1);
	}
	return (0);
}

static int get_ants(char *line, int *nb_ants)
{
	int ant;

	ant = ft_atoi(line);
	if (ant <= 0 || ft_isdigit(ant))
	{
		perror("Not enough ants or not digit");
		return (-1);
	}
	*nb_ants = ant;
	return (0);
}

static int open_file(t_data *data)
{
	char	*line;
	int		argument;
	int 	fd  = open("maps/base_map.txt", O_RDWR);

	/// enlever fd et mettre 0 apres ///
	get_next_line(fd, &line);
	ft_lstinsert(data->map, create_node(line, "t_map"), "t_map");
	if (get_ants(line, &data->nb_ants) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		ft_lstinsert(data->map, create_node(line, "t_map"), "t_map");
		if ((argument = check_line(line, &data->miss_start, &data->miss_end)) > 0)
		{
			if (get_next_line(fd, &line) != 1)
				return (-1);
			ft_lstinsert(data->map, create_node(line, "t_map"), "t_map");
			if (argument == 2)
			{
				if (get_start_end_room(line, &data->start_room, &data->end_room, 0) == -1)
					return (-1);
			}
			else if (argument == 1)
			{
				if (get_start_end_room(line, &data->start_room, &data->end_room, 1) == -1)
					return (-1);
			}
		}
		if (get_count_room_links(line, &data->miss_room, data->rooms, data->links) == -1)
			break ;
	}
	data->map = data->map->next;
	ft_lstreverse(&data->map);
	data->links = data->links->next;
	data->rooms = data->rooms->next;
	if (check_missing_data(data->miss_start, data->miss_end, data->miss_room) == -1)
		return (-1);
	return (0);
}

int main(void)
{
	t_data data;

	declare_structs(&data);
	if (open_file(&data) == -1)
		exit(-1);
	link_rooms(&data);
	assign_ants(&data);
	find_path(data.end_room, data.ants, data.nb_ants, data.start_room);
	return (0);
}
