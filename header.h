/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:15:55 by emammadz          #+#    #+#             */
/*   Updated: 2015/11/28 15:14:02 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> // enlever //
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "libft/libft.h"

#define BUFF_SIZE 50

struct s_path;

typedef struct s_rooms
{
	char        *name;
	int         x;
	int         y;
	void        *next;
}               t_rooms;

typedef struct s_links
{
	char        *room_a;
	char        *room_b;
	void        *next;
}               t_links;

typedef struct s_map
{
	char    *line;
	void    *next;
}               t_map;

typedef struct s_path
{
	char		*name;
	int			x;
	int			y;
	struct 		s_path		**links;
}				t_path;

typedef struct s_data
{
	t_path		*start_room;
	t_path		*end_room;
	bool		miss_start;
	bool		miss_end;
	bool		miss_room;
	t_rooms		*rooms;
	t_links		*links;
	t_map		*map;
}				t_data;

int				get_next_line(int const fd, char **line);
int				get_count_room_links(char *line);
#endif
