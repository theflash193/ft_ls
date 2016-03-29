/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:47:48 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_flags(char option, t_env *e)
{
	if (option == 'a')
		e->flags |= ALL;
	if (option == 'l')
		e->flags |= LONG;
	if (option == 'r')
		e->flags |= REVERSE;
	if (option == 'R')
		e->flags |= RECURSIVE;
	if (option == 't')
		e->flags |= TIME;
	if (option == 'o')
		e->flags |= HIDE_GROUP;
	if (option == 'n')
		e->flags |= DISPLAY_ID;
	if (option == 'A')
		e->flags |= LIST_ALL_ENTRIES;
	if (option == 'c')
		e->flags |= BIRTH_DATE;
	if (option == 'i')
		e->flags |= INO_NUMBER;
}
