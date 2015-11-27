/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:15:55 by emammadz          #+#    #+#             */
/*   Updated: 2015/11/27 17:55:05 by emammadz         ###   ########.fr       */
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
#include "libft/libft.h"

#define BUFF_SIZE 50

typedef struct s_data
{
	char		**start_room;
	char		**end_room;
	bool		miss_start;
	bool		miss_end;
	bool		miss_room;
}				t_data;

int				get_next_line(int const fd, char ** line);

#endif
