/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:35:26 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ps1;

	i = 0;
	if ((ps1 = (char *)malloc((sizeof(*s1) * (ft_strlen(s1)) + 1))))
	{
		while (s1[i] != '\0')
		{
			ps1[i] = s1[i];
			i++;
		}
		ps1[i] = '\0';
		return (ps1);
	}
	else
		return (NULL);
}
