/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:31:43 by grass-kw          #+#    #+#             */
/*   Updated: 2016/02/26 13:50:02 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	behaviour_in_mode_option(char *arg, t_env *e, int *mode_options,
	int *error)
{
	t_path	*new_elem;

	if (ft_strcmp(arg, "--") == 0)
		*mode_options = 0;
	else if (!isfile(arg))
		active_flags(arg, e);
	else
	{
		if ((new_elem = ft_create_elem(arg, e)) == NULL)
			*error = 1;
		else
			ft_path_add(&(e->list_path), new_elem, e);
		*mode_options = 0;
	}
}

static	void	all_arguments_is_file(char *arg, t_env *e, int *error)
{
	t_path	*new_elem;

	if ((new_elem = ft_create_elem(arg, e)) == NULL)
		*error = 1;
	else
		ft_path_add(&(e->list_path), new_elem, e);
}

void			parser(t_env *e, char **av)
{
	int		i;
	int		mode_options;
	int		error;

	mode_options = 1;
	i = 1;
	error = 0;
	while (av[i])
	{
		if (mode_options)
			behaviour_in_mode_option(av[i], e, &mode_options, &error);
		else
			all_arguments_is_file(av[i], e, &error);
		i++;
	}
	if (ft_path_size(&(e->list_path)) == 0 && !error)
		ft_path_add(&(e->list_path), ft_create_elem(".", e), e);
}
