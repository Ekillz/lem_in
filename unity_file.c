/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unity_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:58:57 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/15 16:25:53 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	write_file_links(t_links *links, bool thick)
{
	t_links *tmp;
	int		fd;

	fd = open("/nfs/zfs-student-3/users/emammadz/unity_file/file2.txt",
			O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0755);
	tmp = links;
	while (tmp)
	{
		ft_putstr_fd(tmp->a, fd);
		ft_putchar_fd('-', fd);
		ft_putstr_fd(tmp->b, fd);
		ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
	if (thick)
		ft_putstr_fd("thick", fd);
	close(fd);
}

void		write_file_2(t_rooms *room, int fd)
{
	t_rooms	*tmp;

	tmp = room;
	while (tmp)
	{
		ft_putstr_fd(tmp->name, fd);
		ft_putstr_fd(" ", fd);
		ft_putstr_fd(ft_itoa(tmp->x), fd);
		ft_putstr_fd(" ", fd);
		ft_putstr_fd(ft_itoa(tmp->y), fd);
		ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}

void		write_file(t_data *data)
{
	int		fd;

	write_file_links(data->links, data->thick);
	fd = open("/nfs/zfs-student-3/users/emammadz/unity_file/file.txt",
			O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0755);
	ft_putstr_fd(data->start_room->name, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoa(data->start_room->x), fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoa(data->start_room->y), fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd(data->end_room->name, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoa(data->end_room->x), fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoa(data->end_room->y), fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd(ft_itoa(data->nb_ants), fd);
	ft_putchar_fd('\n', fd);
	write_file_2(data->rooms, fd);
	close(fd);
}
