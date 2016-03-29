/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:40:11 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		get_buffer(t_stat *buffer, struct stat buf)
{
	buffer->st_nlink = buf.st_nlink;
	buffer->st_dev = buf.st_dev;
	buffer->st_ino = buf.st_ino;
	buffer->st_mode = buf.st_mode;
	buffer->st_uid = buf.st_uid;
	buffer->st_gid = buf.st_gid;
	buffer->st_rdev = buf.st_rdev;
	buffer->st_atimespec = buf.st_atimespec;
	buffer->st_mtimespec = buf.st_mtimespec;
	buffer->st_ctimespec = buf.st_ctimespec;
	buffer->st_size = buf.st_size;
	buffer->st_blocks = buf.st_blocks;
	buffer->st_blksize = buf.st_blksize;
	buffer->st_flags = buf.st_flags;
	buffer->st_gen = buf.st_gen;
}

static int		get_stat(char *path, t_stat *buffer)
{
	struct stat buf;
	int			ret;
	char		*error_msg;

	if ((ret = lstat(path, &buf)) == -1)
	{
		error_msg = format_error(path);
		perror(error_msg);
		ft_strclean(error_msg);
		return (-1);
	}
	get_buffer(buffer, buf);
	return (1);
}

t_path			*ft_create_elem(char *elem, t_env *e)
{
	t_path	*ret;

	if ((ret = (t_path *)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	ret->elem = ft_strdup(elem);
	ret->next = NULL;
	ret->link = NULL;
	if (get_stat(elem, &(ret->stat)) == -1)
	{
		ft_path_delone(&ret);
		e->case_invalid = 1;
		return (NULL);
	}
	if (flag_is_active(LONG, e->flags) && !(ret->stat.st_mode & S_IFDIR))
		set_stat_max(ret->stat, e);
	return (ret);
}
