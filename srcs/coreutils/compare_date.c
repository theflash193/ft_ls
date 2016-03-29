/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_date.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:11:27 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		cmp_lexical(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (ft_isupper(s1[i]) && ft_islower(s2[i]))
		return (1);
	return (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0);
}

int				compare_birth_path(t_path *a, t_path *b)
{
	if (a->stat.st_birthtimespec.tv_sec != b->stat.st_birthtimespec.tv_sec)
		return (a->stat.st_birthtimespec.tv_sec >
			b->stat.st_birthtimespec.tv_sec);
		return (cmp_lexical(a->elem, b->elem));
}

int				compare_birth_btree(t_btree *a, t_btree *b)
{
	if (a->stat.st_birthtimespec.tv_sec != b->stat.st_birthtimespec.tv_sec)
		return (a->stat.st_birthtimespec.tv_sec >
			b->stat.st_birthtimespec.tv_sec);
		return (!cmp_lexical(b->name, a->name));
}

int				compare_date_path(t_path *a, t_path *b)
{
	if (a->stat.st_mtime != b->stat.st_mtime)
		return (a->stat.st_mtime < b->stat.st_mtime);
	return (cmp_lexical(a->elem, b->elem));
}

int				compare_date_btree(t_btree *a, t_btree *b)
{
	if (a->stat.st_mtime != b->stat.st_mtime)
		return (a->stat.st_mtime < b->stat.st_mtime);
	return (cmp_lexical(a->name, b->name));
}
