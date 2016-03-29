/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:49:35 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		environnement_initialize(t_env *e)
{
	e->flags = 0;
	e->list_path = NULL;
	e->path = NULL;
	e->useful = 0;
	e->one_path = 0;
	e->total = 0;
	e->current_times = time(NULL);
	e->case_invalid = 0;
	e->nb_link_max = 0;
	e->user_max = 0;
	e->group_max = 0;
	e->size_max = 0;
	e->max_minor = 0;
	e->max_major = 0;
	e->max_ino = 0;
}

static char		*get_linked_file(char *sym_file)
{
	int		ret;
	char	*linked_file;
	char	buf[1024];

	ft_bzero(buf, 1024);
	if ((ret = readlink(sym_file, buf, 1024)) == -1)
		return (NULL);
	linked_file = ft_strdup(buf);
	return (linked_file);
}

void			convert_symlink_to_file(t_path *list_path)
{
	t_path	*cursor;
	char	*str;

	cursor = list_path;
	while (cursor)
	{
		if ((cursor->stat.st_mode & S_IFMT) == S_IFLNK)
		{
			if ((str = get_linked_file(cursor->elem)) != NULL)
				cursor->link = get_linked_file(cursor->elem);
		}
		cursor = cursor->next;
	}
}

int				main(int ac, char **av)
{
	t_env	e;

	(void)ac;
	environnement_initialize(&e);
	parser(&e, av);
	convert_symlink_to_file(e.list_path);
	file(&e);
	find_all_path_files(&e);
	ft_pathdel(&(e.list_path));
	return (0);
}
