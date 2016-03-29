/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:48:17 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	format_long(char *name, t_stat st, t_env *e)
{
	ino_number(st, e);
	file_mode(st);
	number_of_link(st, e);
	owner_name(st, e);
	group_name(st, e);
	number_of_bytes(st, e);
	last_modif(e, st);
	path_name(name, st, e);
}
