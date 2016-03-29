/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   owner_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:04:39 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	owner_name(t_stat st, t_env *e)
{
	struct passwd	*get_name;

	if (((get_name = getpwuid(st.st_uid)) == NULL) ||
		(flag_is_active(DISPLAY_ID, e->flags)))
		ft_putnbr(st.st_uid);
	else
	{
		ft_putstr(get_name->pw_name);
		ft_spaces_characteristics(e->user_max - ft_strlen(get_name->pw_name));
	}
	ft_putchar(' ');
}
