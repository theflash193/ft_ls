/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:46:48 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		insertion_sort(t_path **begin_path, t_path *new_elem,
		int (*cmp)(), t_env *e)
{
	int		position;
	t_path	*cursor;

	(void)e;
	cursor = *begin_path;
	position = 0;
	while (cursor && cmp(new_elem, cursor) > 0)
	{
		cursor = cursor->next;
		position++;
	}
	return (position);
}
