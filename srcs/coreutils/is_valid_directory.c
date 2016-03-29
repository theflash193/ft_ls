/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:23:32 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_dot_directory(t_btree *file)
{
	return (ft_strcmp(file->name, ".") != 0 && ft_strcmp(file->name, "..") != 0
		&& ((file->stat.st_mode & S_IFMT) == S_IFDIR));
}

int		is_valid_directory(t_btree *file)
{
	return (is_dot_directory(file) &&
		file->name[0] != '.');
}

int		open_cached_directory(t_btree *file, t_env *e)
{
	return (flag_is_active(ALL, e->flags) &&
		file->name[0] == '.' && is_dot_directory(file));
}

int		dot_including(t_env *e)
{
	return ((flag_is_active(LONG, e->flags) && flag_is_active(ALL, e->flags)));
}

int		dot_dir_not_including(char *name, t_env *e)
{
	return (flag_is_active(LONG, e->flags) && ft_strcmp(name, ".") != 0 &&
	ft_strcmp(name, "..") != 0 && name[0] != '.');
}
