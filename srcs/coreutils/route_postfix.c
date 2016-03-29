/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_postfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:47:30 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	route_postfix(t_btree *root, t_env e)
{
	if (root->left)
		route_postfix(root->left, e);
	format(root, e);
	if (root->right)
		route_postfix(root->right, e);
}
