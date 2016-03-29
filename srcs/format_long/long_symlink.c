/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_symlink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:48:42 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	path_name(char *name, t_stat st, t_env *e)
{
	int		ret;
	char	buf[1024];
	char	*path;

	path = construct_path(e->path, name);
	(void)name;
	(void)st;
	(void)e;
	ft_bzero(buf, 1024);
	if (st.st_mode & S_IFLNK)
	{
		if ((ret = readlink(path, buf, 1024)) == -1)
			ft_putendl(name);
		else
		{
			ft_putstr(name);
			ft_putstr(" -> ");
			ft_putendl(buf);
		}
	}
	else
		ft_putendl(name);
	free(path);
}
