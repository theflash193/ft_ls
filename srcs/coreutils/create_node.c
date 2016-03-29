/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 14:12:58 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	update_blocks(t_stat stat, t_env *e, char *name)
{
	if (name[0] != '.' || flag_is_active(ALL, e->flags))
		e->total += stat.st_blocks;
}

t_btree		*create_node(struct dirent *dp, t_env *e)
{
	t_btree	*new_node;

	(void)e;
	if ((new_node = (t_btree *)malloc(sizeof(t_btree))) == NULL)
		return (NULL);
	new_node->name = ft_strdup(dp->d_name);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->stat = search_stat(new_node, e->path);
	if ((dot_including(e) || dot_dir_not_including(new_node->name, e))
		|| (hide_group(e)) || (display_id(e)))
	{
		set_stat_max(new_node->stat, e);
		update_blocks(new_node->stat, e, new_node->name);
	}
	return (new_node);
}
