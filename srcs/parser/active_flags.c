/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   active_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:49:43 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_multi_minus(char *s, char **invalid)
{
	size_t	n;
	int		i;

	i = 0;
	n = 0;
	while (s[i++] == '-')
	{
		n++;
	}
	if (n > 2)
	{
		*invalid = ft_strsub(s, 0, n);
		return (1);
	}
	return (0);
}

static int	check_invalid_options(char *s)
{
	char	*invalid;

	if (is_multi_minus(s, &invalid))
	{
		invalid_option(invalid);
		ft_strclean(invalid);
		return (1);
	}
	while (*(++s) != '\0')
	{
		if (!is_option(*s))
		{
			invalid = ft_strndup(s, 1);
			invalid_option(invalid);
			ft_strclean(invalid);
			return (1);
		}
	}
	return (0);
}

void		active_flags(char *s, t_env *e)
{
	(void)e;
	if (check_invalid_options(s))
		exit(0);
	while (*(++s))
		set_flags(*s, e);
}
