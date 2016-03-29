/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:46:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			determine_position(t_path **begin_path, t_path *new_elem,
		t_env *e, int *i)
{
	if (flag_is_active(TIME, e->flags))
		*i = insertion_sort(begin_path, new_elem, compare_date_path, e);
	else if (flag_is_active(BIRTH_DATE, e->flags))
		*i = insertion_sort(begin_path, new_elem, compare_birth_path, e);
	else
		*i = insertion_sort(begin_path, new_elem, compare_name_path, e);
}

static void		if_zero(t_path **begin_path, t_path *new_elem, t_path *cursor)
{
	new_elem->next = cursor;
	*begin_path = new_elem;
}

void			ft_path_add(t_path **begin_path, t_path *new_elem, t_env *e)
{
	t_path			*cursor;
	unsigned int	size;
	int				i;

	determine_position(begin_path, new_elem, e, &i);
	size = ft_path_size(begin_path);
	cursor = *begin_path;
	if (i == 0 && size == 0)
		*begin_path = new_elem;
	else if (i == 0 && size != 0)
		if_zero(begin_path, new_elem, cursor);
	else
	{
		while ((i-- - 1))
			cursor = cursor->next;
		if (cursor == NULL)
			cursor->next = new_elem;
		else
		{
			new_elem->next = cursor->next;
			cursor->next = new_elem;
		}
	}
}
