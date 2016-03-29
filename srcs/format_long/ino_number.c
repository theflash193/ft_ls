/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ino_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:48:35 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ino_number(t_stat st, t_env *e)
{
	if (flag_is_active(INO_NUMBER, e->flags))
	{
		ft_spaces_characteristics(e->max_ino - len_number(st.st_ino));
		ft_putnbr(st.st_ino);
		ft_putchar(' ');
	}
}
