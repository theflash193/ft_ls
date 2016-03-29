/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:05:02 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	total_size(t_env *e)
{
	ft_putstr("total ");
	ft_putnbr(e->total);
	ft_putchar('\n');
	e->total = 0;
}

void	display_files(t_btree *files, t_env *e)
{
	void (*route)(t_btree *root, t_env e);

	route = (flag_is_active(REVERSE, e->flags)) ? &route_postfix :
		&route_suffix;
	print_path(e->path, e);
	if ((flag_is_active(LONG, e->flags)) ||
		(flag_is_active(HIDE_GROUP, e->flags)))
		total_size(e);
	display_btree(files, route, *e);
}
