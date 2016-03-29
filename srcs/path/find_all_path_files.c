/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_path_files.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:50:25 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		find_all_path_files(t_env *e)
{
	t_path	*cursour;

	if (e->case_invalid)
		e->one_path = 0;
	else
		e->one_path = (ft_path_size(&(e->list_path)) == 1) ? 1 : 0;
	initialize_max(e);
	cursour = e->list_path;
	while (cursour)
	{
		if (cursour == e->list_path->next)
			e->useful = 1;
		find_files(cursour->elem, *e);
		initialize_max(e);
		cursour = cursour->next;
	}
}
