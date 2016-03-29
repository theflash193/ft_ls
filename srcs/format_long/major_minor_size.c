/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major_minor_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:48:57 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	number_of_bytes(t_stat st, t_env *e)
{
	if (!(S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode)))
	{
		ft_spaces_characteristics(e->size_max - len_number(st.st_size));
		ft_putnbr(st.st_size);
	}
	else
	{
		ft_putchar(' ');
		ft_spaces_characteristics(e->max_major - len_number(major(st.st_rdev)));
		ft_putnbr(major(st.st_rdev));
		ft_putstr(", ");
		ft_spaces_characteristics(e->max_minor - len_number(minor(st.st_rdev)));
		ft_putnbr(minor(st.st_rdev));
	}
	ft_putchar(' ');
}
