/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:05:28 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	group_name(t_stat st, t_env *e)
{
	struct group	*get_grp_name;

	ft_putchar(' ');
	if (!(flag_is_active(HIDE_GROUP, e->flags)))
	{
		if (((get_grp_name = getgrgid(st.st_gid)) == NULL) ||
			(flag_is_active(DISPLAY_ID, e->flags)))
			ft_putnbr(st.st_gid);
		else
		{
			ft_putstr(get_grp_name->gr_name);
			ft_spaces_characteristics(e->group_max -
				ft_strlen(get_grp_name->gr_name));
		}
		ft_putstr("  ");
	}
}
