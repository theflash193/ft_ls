/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:35:57 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dst_mem;

	dst_mem = ft_strlen(dst);
	i = 0;
	if (size <= dst_mem)
		return (size + ft_strlen(src));
	while (dst_mem + i < (size - 1) && src[i] != '\0')
	{
		dst[i + dst_mem] = src[i];
		i++;
	}
	dst[i + dst_mem] = '\0';
	return (dst_mem + ft_strlen(src));
}
