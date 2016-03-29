/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:35:51 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tmp;
	char	*len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tmp = ft_strlen(s1) + ft_strlen(s2);
	if (!(len = (char *)malloc(sizeof(*len) * tmp + 1)))
		return (NULL);
	while (s1[i])
	{
		len[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		len[i] = s2[j];
		i++;
		j++;
	}
	len[i] = '\0';
	return (len);
}
