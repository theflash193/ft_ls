/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:04:07 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	list_all_entries(char *name, t_env *e)
{
	return ((flag_is_active(LIST_ALL_ENTRIES, e->flags)) &&
		(ft_strcmp(name, ".") != 0) && (ft_strcmp(name, "..") != 0));
}

static int	print_visible(char *name, t_env *e)
{
	return (flag_is_active(ALL, e->flags) == 0 && !is_cached(name));
}

void		format(t_btree *root, t_env e)
{
	if (flag_is_active(ALL, e.flags) || print_visible(root->name, &e) ||
		(list_all_entries(root->name, &e)))
	{
		if ((flag_is_active(LONG, e.flags)) ||
			(flag_is_active(HIDE_GROUP, e.flags) ||
			(flag_is_active(DISPLAY_ID, e.flags))))
			format_long(root->name, root->stat, &e);
		else
			format_basic(root->name, &e, root->stat);
	}
}
