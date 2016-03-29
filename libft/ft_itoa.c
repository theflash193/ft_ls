/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:29:12 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:29:14 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_length(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = n * -1;
	while (n > 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_length(n) + 1;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (n == 0)
		return (ft_strcpy(str, "0"));
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	else
		i--;
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}
