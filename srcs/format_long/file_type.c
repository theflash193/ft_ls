/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:48:12 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_file_type(t_stat st)
{
	if (((st.st_mode & S_IFMT) == S_IFCHR))
		ft_putstr("c");
	if (((st.st_mode & S_IFMT) == S_IFLNK))
		ft_putstr("l");
	else if (((st.st_mode & S_IFMT) == S_IFDIR))
		ft_putstr("d");
	else if (((st.st_mode & S_IFMT) == S_IFBLK))
		ft_putstr("b");
	else if (((st.st_mode & S_IFMT) == S_IFSOCK))
		ft_putstr("s");
	else if (((st.st_mode & S_IFMT) == S_IFREG))
		ft_putstr("-");
}
