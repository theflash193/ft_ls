/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:39:49 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_btree		*add_node(t_btree *root, t_btree *new_node, int (*cmp)())
{
	if (!root)
		return (new_node);
	if (cmp(new_node, root) == 1)
		root->left = add_node(root->left, new_node, cmp);
	else
		root->right = add_node(root->right, new_node, cmp);
	return (root);
}
