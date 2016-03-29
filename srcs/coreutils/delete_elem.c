/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:40:25 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_path	*previous(t_path *root, char *elem)
{
	t_path	*cursor;

	cursor = root;
	while (cursor)
	{
		if (ft_strcmp(cursor->next->elem, elem) == 0)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

void			delete_elem(char *elem, t_path **root)
{
	t_path	*cursor;
	t_path	*delete_elem;
	t_path	*prev;

	cursor = *root;
	while (cursor)
	{
		if (ft_strcmp(cursor->elem, elem) == 0)
		{
			delete_elem = cursor;
			cursor = cursor->next;
			if (*root == delete_elem)
				*root = cursor;
			else
			{
				prev = previous(*root, delete_elem->elem);
				prev->next = cursor;
			}
			ft_path_delone(&delete_elem);
			return ;
		}
		else
			cursor = cursor->next;
	}
}
