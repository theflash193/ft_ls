/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:20 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:31:22 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			*ptr_dst;
	unsigned const char		*ptr_src;
	unsigned char			value;

	i = 0;
	ptr_dst = dst;
	ptr_src = src;
	value = c;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == value)
		{
			i++;
			return ((void *)dst + i);
		}
		i++;
	}
	return (NULL);
}
