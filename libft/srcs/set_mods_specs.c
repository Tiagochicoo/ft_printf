/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mods_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:52:37 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/18 23:28:23 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_modifiers(char **input, t_arg *arg_struct)
{
	char	*modifiers;
	int		i;

	i = 0;
	modifiers = NULL;
	if (ft_strchr(MODIFIERS, **input) != NULL)
		modifiers = malloc(sizeof(*input) + 1);
	while (**input && ft_strchr(MODIFIERS, **input))
	{
		modifiers[i] = **input;
		input++;
		i++;
	}
	if (modifiers)
	{
		modifiers[i] = '\0';
		arg_struct->modifiers = modifiers;
	}
}

void	set_specifier(char **input, t_arg *arg_struct)
{
	char	specifier;

	specifier = **input;
	if (!(ft_isalpha(specifier) || specifier == '%'))
		return ;
	(*input)++;
	arg_struct->specifier = specifier;
}
