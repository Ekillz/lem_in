/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unity_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:58:57 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/09 17:25:26 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	write_file_links(t_links *links)
{
	t_links *tmp;
	int		fd;

	fd = open("/nfs/zfs-student-3/users/emammadz/unity_file/file2.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0755);
	tmp = links;
	while (tmp)
	{
		ft_putstr_fd(tmp->a, fd);
		ft_putchar_fd('-', fd);
		ft_putstr_fd(tmp->b, fd);
		ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}

void		write_file(t_data *data)
{
	int		fd;
	t_rooms	*tmp;

	write_file_links(data->links);
	fd = open("/nfs/zfs-student-3/users/emammadz/unity_file/file.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, 0755);
	ft_putstr_fd(data->start_room->name, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoa(data->start_room->x), fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoa(data->start_room->y), fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd(ft_itoa(data->nb_ants), fd);
	ft_putchar_fd('\n', fd);
	tmp = data->rooms;
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
	close(fd);
}
