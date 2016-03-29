/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_stat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:47:43 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_stat	search_stat(t_btree *file, char *path)
{
	t_stat		stat;
	struct stat	buf;
	char		*new_path;

	new_path = construct_path(path, file->name);
	lstat(new_path, &buf);
	stat.st_nlink = buf.st_nlink;
	stat.st_dev = buf.st_dev;
	stat.st_ino = buf.st_ino;
	stat.st_mode = buf.st_mode;
	stat.st_uid = buf.st_uid;
	stat.st_gid = buf.st_gid;
	stat.st_rdev = buf.st_rdev;
	stat.st_atimespec = buf.st_atimespec;
	stat.st_mtimespec = buf.st_mtimespec;
	stat.st_ctimespec = buf.st_ctimespec;
	stat.st_size = buf.st_size;
	stat.st_blocks = buf.st_blocks;
	stat.st_blksize = buf.st_blksize;
	stat.st_flags = buf.st_flags;
	stat.st_gen = buf.st_gen;
	ft_strclean(new_path);
	return (stat);
}
