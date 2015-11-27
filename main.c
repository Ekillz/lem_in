/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:06:53 by emammadz          #+#    #+#             */
/*   Updated: 2015/11/27 17:55:02 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int get_start_end_room(char *line, char **start_room, char **end_room, int which)
{
	if (which == 0)
	{
		start_room = ft_strsplit(line, ' ');
		if (!start_room[0] || !start_room[1] || !start_room[2] ||
				ft_isdigit(ft_atoi(start_room[1])) || ft_isdigit(ft_atoi(start_room[2])))
			return (-1);
	}
	else
	{
		end_room = ft_strsplit(line, ' ');
		if (!end_room[0] || !end_room[1] || !end_room[2] ||
				ft_isdigit(ft_atoi(end_room[1])) || ft_isdigit(ft_atoi(end_room[2])))
			return (-1);
	}
	return (0);
}

static int check_line(char *line, bool *miss_start, bool *miss_end)
{
	if (ft_strcmp("##start", line))
	{
		miss_start = false;
		return (2);
	}
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

	get_next_line(0, &line);
	if (get_ants(line) == -1)
		return (-1);
	while (get_next_line(0, &line))
	{
		if ((argument = check_line(line, &data->miss_start, &data->miss_end)) > 0)
		{
			get_next_line(0, &line);
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
	if (data.miss_start || data.miss_end)
	{
		perror("Error: There is no start or end\n");
		return (-1);
	}
	if (data.miss_room)
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
