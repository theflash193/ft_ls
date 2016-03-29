/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:32:48 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdata(void *data, char const *str, int mode)
{
	ft_putstr(str);
	ft_putstr(" :");
	if (mode == 1)
		ft_putstr((char *)data);
	else if (mode == 2)
		ft_putnbr((int)data);
	ft_putstr(" ");
}
