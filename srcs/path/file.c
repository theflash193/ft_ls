/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:50:20 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			link_is_directory(t_path *file, t_env *e)
{
	int				ret;
	struct stat		buf;
	char			*path;

	if ((file->stat.st_mode & S_IFMT) == S_IFLNK)
	{
		if (flag_is_active(LONG, e->flags))
		{
			path = construct_path("/", file->link);
			if ((ret = lstat(path, &buf)) == -1)
			{
				ft_strclean(path);
				return (0);
			}
			ret = ((buf.st_mode & S_IFMT) == S_IFDIR) ? 1 : 0;
			ft_strclean(path);
			return (ret);
		}
	}
	return (0);
}

static void			ft_print_file(t_env *e, t_path *cursor, int bool,
	t_path *tmp)
{
	while (cursor)
	{
		if ((!(cursor->stat.st_mode & S_IFDIR) && link_is_directory(cursor, e))
			|| !(cursor->stat.st_mode & S_IFDIR))
		{
			bool = 1;
			if (flag_is_active(LONG, e->flags))
			{
				e->path = ft_strdup("/");
				format_long(cursor->elem, cursor->stat, e);
				ft_strclean(e->path);
			}
			else
				format_basic(cursor->elem, e, cursor->stat);
			tmp = cursor;
			cursor = cursor->next;
			delete_elem(tmp->elem, &e->list_path);
		}
		else
			cursor = cursor->next;
	}
}

void				file(t_env *e)
{
	t_path			*tmp;
	t_path			*cursor;
	int				bool;

	bool = 0;
	tmp = NULL;
	cursor = e->list_path;
	ft_print_file(e, cursor, bool, tmp);
	if (bool == 1)
		e->useful = 1;
}
