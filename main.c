/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:06:53 by emammadz          #+#    #+#             */
/*   Updated: 2015/11/28 15:13:59 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int get_start_end_room(char *line, t_path *start_room, t_path *end_room, int which)
{
	char	**datas;

	datas = ft_strsplit(line, ' ');
	if (!datas[0] || !datas[1] || !datas[2] ||
			ft_isdigit(ft_atoi(datas[1])) || ft_isdigit(ft_atoi(datas[2])))
		return (-1);
	if (which == 0)
	{
		start_room = malloc(sizeof(t_path));
		start_room->name = datas[0];
		start_room->x = ft_atoi(datas[1]);
		start_room->y = ft_atoi(datas[2]);
	}
	else
	{
		end_room = malloc(sizeof(t_path));
		end_room->name = datas[0];
		end_room->x = ft_atoi(datas[1]);
		end_room->y = ft_atoi(datas[2]);
	}
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
	else if (line[0] == '#')
		return (3);
	return (0);
}

static int get_ants(char *line)
{
	int ant;

	ant = ft_atoi(line);
	if (ant <= 0 || ft_isdigit(ant))
	{
		perror("Not enough ants or not digit");
		return (-1);
	}
	return (0);
}

static int open_file(t_data *data)
{
	char	*line;
	int		argument;
	int 	fd  = open("maps/base_map.txt", O_RDWR);
	/// enlever fd et mettre 0 apres //
	get_next_line(fd, &line);
	if (get_ants(line) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		if ((argument = check_line(line, &data->miss_start, &data->miss_end)) > 0)
		{
			get_next_line(fd, &line);
			if (argument == 2)
			{
				if (get_start_end_room(line, data->start_room, data->end_room, 0) == -1)
					return (-1);
			}
			else if (argument == 1)
			{
				if (get_start_end_room(line, data->start_room, data->end_room, 1) == -1)
					return (-1);
			}
		}
	}

	// put in a error function //
	if (data->miss_start || data->miss_end)
	{
		perror("Error: There is no start or end\n");
		return (-1);
	}
	if (data->miss_room)
	{
		perror("There is no room\n");
		return (-1);
	}
	return (0);
}

int main(void)
{
	t_data data;

	data.miss_start = true;
	data.miss_end = true;
	data.miss_room = true;
	if (open_file(&data) == -1)
		exit(-1);
	return (0);
}
