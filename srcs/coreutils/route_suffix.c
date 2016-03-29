/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_suffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:47:36 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	route_suffix(t_btree *root, t_env e)
{
	if (root->right)
		route_suffix(root->right, e);
	format(root, e);
	if (root->left)
		route_suffix(root->left, e);
}
