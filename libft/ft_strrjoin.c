/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:37:23 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrjoin(char *s1, char *s2, int pos)
{
	int		i;
	int		j;
	int		cut;
	char	*str;

	str = (char *)malloc(sizeof(int) * ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (i < pos)
	{
		str[i] = s1[i];
		i++;
	}
	cut = i;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	while (s1[cut] != '\0')
		str[i++] = s1[cut++];
	str[i] = '\0';
	return (str);
}
