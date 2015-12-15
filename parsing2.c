/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:45:52 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/15 16:24:11 by emammadz         ###   ########.fr       */
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
		alloc_start_end(&data->start_room, datas, &data->miss_start, which);
	else
		alloc_start_end(&data->end_room, datas, &data->miss_end, which);
	ft_freetab(datas);
	return (true);
}

static int	check_line(char *line, bool *thick)
{
	if (ft_strequ("##start", line))
		return (2);
	else if (ft_strequ("##end", line))
		return (1);
	else if (ft_strequ("##thick", line))
		*thick = true;
	return (0);
}

void		read_map_loop(t_data *data, char *line, int argument)
{
	while (get_next_line(0, &line))
	{
		ft_lstinsert(data->map, create_node(line, "t_map"), "t_map");
		if ((argument = check_line(line, &data->thick)) > 0)
		{
			while (get_next_line(0, &line))
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
		if (get_count_room_links(line, &data->miss_room,
					data->rooms, data->links) == -1)
			break ;
	}
}

void		alloc_start_end(t_rooms **room, char **datas, bool *miss, int which)
{
	if (which == 0)
	{
		*miss = false;
		*room = malloc(sizeof(t_rooms));
		(*room)->name = ft_strdup(datas[0]);
		(*room)->x = ft_atoi(datas[1]);
		(*room)->y = ft_atoi(datas[2]);
	}
	else
	{
		*miss = false;
		*room = malloc(sizeof(t_rooms));
		(*room)->name = ft_strdup(datas[0]);
		(*room)->x = ft_atoi(datas[1]);
		(*room)->y = ft_atoi(datas[2]);
	}
}
