/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:40:03 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*construct_path(char *path_racine, char *directory)
{
	char	*new_path;
	char	*tmp;
	int		i;

	i = 0;
	while (path_racine[i] != '\0')
		i++;
	if (path_racine[i - 1] != '/')
	{
		tmp = ft_strjoin(path_racine, "/");
		new_path = ft_strjoin(tmp, directory);
		ft_strclean(tmp);
	}
	else
		new_path = ft_strjoin(path_racine, directory);
	return (new_path);
}
