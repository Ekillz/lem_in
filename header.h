/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:15:55 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/04 13:49:47 by emammadz         ###   ########.fr       */
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
	struct s_rooms *next;
}               t_rooms;

typedef struct s_links
{
	char		*a;
	char		*b;
	struct s_links *next;
}               t_links;

typedef struct s_map
{
	char	*line;
	struct s_map *next;
}               t_map;

typedef struct s_path
{
	char		*name;
	int			x;
	int			y;
	int			nb_links;
	bool		is_free;
	struct 		s_path		**links;
}				t_path;

typedef struct	s_ant
{
	t_map		*last_path; // assign when ant moves //
	t_path		*path;
}				t_ant;

typedef struct s_data
{
	t_rooms		*start_room;
	t_rooms		*end_room;
	bool		miss_start;
	bool		miss_end;
	bool		miss_room;
	int			nb_ants;
	t_map		*map;
	t_rooms		*rooms;
	t_links		*links;
	t_path		**paths;
	t_ant		**ants;
}				t_data;

int				get_next_line(int const fd, char **line);
int				get_count_room_links(char *line, bool *miss_room, t_rooms *rooms, t_links *link);
void			ft_lstinsert(void *alst, void *new, const char *type);
void			ft_lstreverse(t_map **map);
int				check_missing_data(bool start, bool end, bool room);
void			*create_node(void *data, const char *type);
void			declare_structs(t_data *data);
void			link_rooms(t_data *data);
void			assign_ants(t_data *data);
t_path			*get_room_by_name(t_path **all_paths, const char *name);
void			find_path(t_rooms *start, t_rooms *end, t_ant **ants);
int				compare_last_path(t_ant *ant, int i);
int				check_last_path_2(int *sorted_tab, int *e, int *i);
#endif
