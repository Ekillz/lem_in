/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:22:18 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/14 16:37:20 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && del)
	{
		if (*alst)
		{
			ft_lstdel(&((*alst)->next), del);
			ft_lstdelone(alst, del);
		}
	}
}
