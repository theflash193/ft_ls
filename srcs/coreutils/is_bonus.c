/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 14:21:55 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:22:47 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		hide_group(t_env *e)
{
	return (flag_is_active(HIDE_GROUP, e->flags));
}

int		display_id(t_env *e)
{
	return (flag_is_active(DISPLAY_ID, e->flags));
}
