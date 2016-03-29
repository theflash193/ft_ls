/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:46:30 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_pathdel(t_path **begin_path)
{
	t_path	*cursor;
	t_path	*tmp;

	cursor = *begin_path;
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->next;
		ft_path_delone(&tmp);
	}
	*begin_path = NULL;
}
