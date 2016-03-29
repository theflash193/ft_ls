/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:46:01 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_basic(char *path, t_env *e, t_stat st)
{
	if (flag_is_active(INO_NUMBER, e->flags))
	{
		ft_putnbr(st.st_ino);
		ft_putchar(' ');
	}
	ft_putendl(path);
}
