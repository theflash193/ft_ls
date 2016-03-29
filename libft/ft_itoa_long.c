/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:28:53 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:28:54 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_long_length(long long int nb)
{
	long long int	length;

	if (nb >= 0)
		length = 1;
	else
		length = 2;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		length++;
	}
	return (length);
}

char		*ft_itoa_long(long long int n)
{
	long long int	i;
	char			*result;
	int				sign;

	sign = 1;
	i = ft_itoa_long_length(n);
	if (n < 0)
		sign = -1;
	if (!(result = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	result[i--] = '\0';
	while (i >= (sign < 0) ? 1 : 0)
	{
		if (n < 0)
			result[i] = (-(n % 10) + '0');
		if (n >= 0)
			result[i] = ((n % 10) + '0');
		n = n / 10;
		i--;
	}
	if (sign < 0)
		result = ft_strdup(result + 1);
	return (result);
}
