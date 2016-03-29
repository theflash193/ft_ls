/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyed_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:50:08 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	destroyed_files(t_btree *files, t_env *e)
{
	void (*destroyed)(t_btree **root, t_env e);

	destroyed = (flag_is_active(REVERSE, e->flags)) ? &destroyed_postfix :
		&destroyed_suffix;
	destroyed(&files, *e);
}

void	destroyed_postfix(t_btree **root, t_env e)
{
	t_btree	*tmp_left;
	t_btree *tmp_right;
	t_btree *tmp;

	tmp = *root;
	tmp_right = tmp->right;
	tmp_left = tmp->left;
	if (tmp_left)
		destroyed_postfix(&tmp_left, e);
	if (flag_is_active(RECURSIVE, e.flags) && (is_valid_directory(tmp)
		|| open_cached_directory(tmp, &e)))
	{
		e.save_path = e.path;
		e.tmp_path = construct_path(e.path, tmp->name);
		find_files(e.tmp_path, e);
		ft_strclean(e.tmp_path);
		e.path = e.save_path;
	}
	delete_node(root);
	free((*root));
	if (tmp_right)
		destroyed_postfix(&tmp_right, e);
}

void	destroyed_suffix(t_btree **root, t_env e)
{
	t_btree	*tmp_left;
	t_btree *tmp_right;
	t_btree *tmp;

	tmp = *root;
	tmp_right = tmp->right;
	tmp_left = tmp->left;
	if (tmp_right)
		destroyed_suffix(&tmp_right, e);
	if (flag_is_active(RECURSIVE, e.flags) && (is_valid_directory(tmp) ||
	open_cached_directory(tmp, &e)))
	{
		e.save_path = e.path;
		e.tmp_path = construct_path(e.path, tmp->name);
		find_files(e.tmp_path, e);
		ft_strclean(e.tmp_path);
		e.path = e.save_path;
	}
	delete_node(root);
	free((*root));
	if (tmp_left)
		destroyed_suffix(&tmp_left, e);
}
