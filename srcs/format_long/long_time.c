/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:48:51 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	format_date_hour(char *date)
{
	char *fmt;

	fmt = ft_strsub(date, 4, 12);
	ft_putstr(fmt);
	ft_strclean(fmt);
}

static void	format_date_year(char *date)
{
	char	*fmt;
	char	*year;

	fmt = ft_strsub(date, 4, 7);
	year = ft_strsub(date, 19, 5);
	ft_putstr(fmt);
	ft_putstr(year);
	ft_strclean(fmt);
	ft_strclean(year);
}

void		last_modif(t_env *e, t_stat st)
{
	int curtimes;
	int modif_filestimes;

	curtimes = e->current_times;
	modif_filestimes = st.st_mtime;
	if (((curtimes - modif_filestimes) >= 15724800) ||
			((curtimes - (time_t)(modif_filestimes)) <= -15724800))
		format_date_year(ctime(&st.st_mtime));
	else
		format_date_hour(ctime(&st.st_mtime));
	ft_putchar(' ');
}
