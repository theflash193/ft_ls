/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sticky_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:49:24 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_sticky_bit(t_stat st)
{
	if (!(st.st_mode & S_IXOTH) && (st.st_mode & S_ISVTX))
		ft_putstr("T");
	else if ((st.st_mode & S_IXOTH) && (st.st_mode & S_ISVTX))
		ft_putstr("t");
	else
		(st.st_mode & S_IXOTH) ? ft_putstr("x") : ft_putstr("-");
}

static void	ft_group_permissions(t_stat st)
{
	if (!(st.st_mode & S_IXGRP) && (st.st_mode & S_ISGID))
		ft_putstr("S");
	else if ((st.st_mode & S_IXGRP) && (st.st_mode & S_ISGID))
		ft_putstr("s");
	else
		(st.st_mode & S_IXGRP) ? ft_putstr("x") : ft_putstr("-");
}

static void	ft_user_permissions(t_stat st)
{
	if (!(st.st_mode & S_IXUSR) && (st.st_mode & S_ISUID))
		ft_putstr("S");
	else if ((st.st_mode & S_IXUSR) && (st.st_mode & S_ISUID))
		ft_putstr("s");
	else
		(st.st_mode & S_IXUSR) ? ft_putstr("x") : ft_putstr("-");
}

void		ft_long_permissions(t_stat st)
{
	(st.st_mode & S_IRUSR) ? ft_putstr("r") : ft_putstr("-");
	(st.st_mode & S_IWUSR) ? ft_putstr("w") : ft_putstr("-");
	ft_user_permissions(st);
	(st.st_mode & S_IRGRP) ? ft_putstr("r") : ft_putstr("-");
	(st.st_mode & S_IWGRP) ? ft_putstr("w") : ft_putstr("-");
	ft_group_permissions(st);
	(st.st_mode & S_IROTH) ? ft_putstr("r") : ft_putstr("-");
	(st.st_mode & S_IWOTH) ? ft_putstr("w") : ft_putstr("-");
	ft_sticky_bit(st);
}
