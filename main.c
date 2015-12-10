/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:06:53 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/10 18:02:33 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	get_start_end_room(char *line, t_data *data, int which)
{
	char	**datas;

	datas = ft_strsplit(line, ' ');
	if (!datas[0] || !datas[1] || !datas[2] ||
			ft_isdigit(ft_atoi(datas[1])) || ft_isdigit(ft_atoi(datas[2])))
	{
		ft_freetab(datas);
		return (false);
	}
	if (which == 0)
	{
		data->miss_start = false;
		data->start_room = malloc(sizeof(t_rooms));
		data->start_room->name = ft_strdup(datas[0]);
		data->start_room->x = ft_atoi(datas[1]);
		data->start_room->y = ft_atoi(datas[2]);
	}
	else
	{
		data->miss_end = false;
		data->end_room = malloc(sizeof(t_rooms));
		data->end_room->name = ft_strdup(datas[0]);
		data->end_room->x = ft_atoi(datas[1]);
		data->end_room->y = ft_atoi(datas[2]);
	}
	ft_freetab(datas);
	return (true);
}

static int check_line(char *line)
{
	if (ft_strequ("##start", line))
		return (2);
	else if (ft_strequ("##end", line))
		return (1);
	return (0);
}

static int get_ants(char *line, int *nb_ants)
{
	int ant;

	ant = ft_atoi(line);
	if (ant <= 0)
	{
		printf("%d", ft_isdigit(ant));
		ft_putendl("Not enough ants or not digit");
		return (-1);
	}
	*nb_ants = ant;
	return (0);
}

static int open_file(t_data *data)
{
	char	*line;
	int		argument;
	int		fd;

	fd = 0;
	get_next_line(fd, &line);
	ft_lstinsert(data->map, create_node(line, "t_map"), "t_map");
	if (get_ants(line, &data->nb_ants) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		ft_lstinsert(data->map, create_node(line, "t_map"), "t_map");
		if ((argument = check_line(line)) > 0)
		{
			while (get_next_line(fd, &line))
			{
				ft_lstinsert(data->map, create_node(line, "t_map"), "t_map");
				if (argument == 2)
				{
					if (get_start_end_room(line, data, 0))
						break ;
				}
				else if (argument == 1)
				{
					if (get_start_end_room(line, data, 1))
						break ;
				}
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
	show_map(data.map);
	write_file(&data);
	find_path(data.end_room, data.ants, data.nb_ants, data.start_room);
	return (0);
}
