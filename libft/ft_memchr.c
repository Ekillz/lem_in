/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emammadz <emammadz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:35:03 by emammadz          #+#    #+#             */
/*   Updated: 2015/12/14 16:38:10 by emammadz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			car;
	const unsigned char		*ptr;

	car = (unsigned char)c;
	ptr = (const unsigned char*)s;
	while (n)
	{
		if (*ptr == car)
			return ((void*)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
