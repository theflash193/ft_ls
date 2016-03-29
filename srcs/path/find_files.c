/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:50:32 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			managed_error(char *path, t_env *e)
{
	char			*file_name;
	char			*error_message;

	print_path(path, e);
	file_name = get_file_name(path);
	error_message = format_error(file_name);
	perror(error_message);
	ft_strclean(error_message);
	ft_strclean(file_name);
}

void				find_files(char *path, t_env e)
{
	DIR				*dir;
	struct dirent	*dp;
	t_btree			*files;

	e.path = path;
	files = NULL;
	if ((dir = opendir(path)) == NULL)
	{
		managed_error(e.path, &e);
		return ;
	}
	while ((dp = readdir(dir)) != NULL)
	{
		if (flag_is_active(TIME, e.flags))
			files = add_node(files, create_node(dp, &e), compare_date_btree);
		else if (flag_is_active(BIRTH_DATE, e.flags))
			files = add_node(files, create_node(dp, &e), compare_birth_btree);
		else
			files = add_node(files, create_node(dp, &e), compare_name_btree);
	}
	display_files(files, &e);
	destroyed_files(files, &e);
	closedir(dir);
}
