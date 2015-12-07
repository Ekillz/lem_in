/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:52:30 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/07 17:16:14 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int check_missing_data(bool start, bool end, bool room)
{
	if (start || end)
	{
		ft_putendl("Error: There is no start or end");
		return (-1);
	}
	if (room)
	{
		ft_putendl("There is no room");
		return (-1);
	}
	return (0);
}
