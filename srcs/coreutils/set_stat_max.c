/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stat_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:20:05 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	initialize_max(t_env *e)
{
	e->nb_link_max = 0;
	e->user_max = 0;
	e->group_max = 0;
	e->size_max = 0;
}

int		len_number(int nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

void	set_stat_max(t_stat st, t_env *e)
{
	struct passwd	*get_name;
	struct group	*get_grp_name;
	int				len_name;
	int				len_grp;

	get_name = getpwuid(st.st_uid);
	get_grp_name = getgrgid(st.st_gid);
	len_name = ft_strlen(get_name->pw_name);
	len_grp = ft_strlen(get_grp_name->gr_name);
	if (e->nb_link_max < len_number(st.st_nlink))
		e->nb_link_max = len_number(st.st_nlink);
	if (e->user_max < len_name)
		e->user_max = len_name;
	if (e->group_max < len_grp)
		e->group_max = len_grp;
	if (e->size_max < len_number(st.st_size))
		e->size_max = len_number(st.st_size);
	if (e->max_major < len_number(major(st.st_rdev)))
		e->max_major = len_number(major(st.st_rdev));
	if (e->max_minor < len_number(minor(st.st_rdev)))
		e->max_minor = len_number(minor(st.st_rdev));
	if ((flag_is_active(INO_NUMBER, e->flags) &&
		(e->max_ino < len_number(st.st_ino))))
		e->max_ino = len_number(st.st_ino);
}
