/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:52:30 by emammadz          #+#    #+#             */
/*   Updated: 2015/11/30 16:06:09 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int check_missing_data(bool start, bool end, bool room)
{
	if (start || end)
	{
		perror("Error: There is no start or end\n");
		return (-1);
	}
	if (room)
	{
		perror("There is no room\n");
		return (-1);
	}
	return (0);
}
