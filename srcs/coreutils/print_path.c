/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:47:25 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_path(char *path, t_env *e)
{
	if (e->useful)
		ft_putendl("");
	else
		e->useful = 1;
	if (!(e->one_path == 1))
	{
		ft_putstr(path);
		ft_putendl(":");
	}
	if (e->one_path == 1)
		e->one_path = 0;
}
