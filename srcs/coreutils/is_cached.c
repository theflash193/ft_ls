/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cached.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:46:53 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_cached(char *name)
{
	return (name[0] == '.' || ft_strcmp(name, ".") == 0
		|| ft_strcmp(name, "..") == 0);
}