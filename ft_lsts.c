/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:59:21 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/14 17:12:06 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			ft_lstinsert(void *alst, void *new, const char *type)
{
	if (!new)
		return ;
	if (ft_strequ(type, "t_map"))
	{
		((t_map *)new)->next = ((t_map *)alst)->next;
		((t_map *)alst)->next = (t_map *)new;
	}
	else if (ft_strequ(type, "t_rooms"))
	{
		((t_rooms*)new)->next = ((t_rooms *)alst)->next;
		((t_rooms*)alst)->next = (t_rooms *)new;
	}
	else if (ft_strequ(type, "t_links"))
	{
		((t_links *)new)->next = ((t_links *)alst)->next;
		((t_links *)alst)->next = (t_links *)new;
	}
}

void			ft_lstreverse(t_map **map)
{
	t_map *cursor;
	t_map *next;

	cursor = NULL;
	while (*map)
	{
		next = (*map)->next;
		(*map)->next = cursor;
		cursor = *map;
		*map = next;
	}
	*map = cursor;
}

static void		*create_rooms_node(void *data)
{
	t_rooms *room;

	room = malloc(sizeof(t_rooms));
	room->name = ft_strdup(((char**)data)[0]);
	room->x = ft_atoi(((char **)data)[1]);
	room->y = ft_atoi(((char **)data)[2]);
	return ((void*)room);
}

void			*create_node(void *data, const char *type)
{
	t_map	*map;
	t_links	*link;

	if (ft_strequ(type, "t_map"))
	{
		map = malloc(sizeof(t_map));
		map->line = ft_strdup((char *)data);
		return ((void *)map);
	}
	else if (ft_strequ(type, "t_rooms"))
		return (create_rooms_node(data));
	else if (ft_strequ(type, "t_links"))
	{
		link = malloc(sizeof(t_links));
		link->a = ft_strdup(((char **)data)[0]);
		link->b = ft_strdup(((char **)data)[1]);
		return ((void *)link);
	}
	return (NULL);
}
