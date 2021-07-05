/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mods_specs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:23:37 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 15:20:48 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_specifier(char **input, t_arg *arg_struct)
{
	char	specifier;

	specifier = **input;
	if (!(ft_isalpha(specifier)) && specifier != '%')
		return ;
	(*input)++;
	arg_struct->specifier = (char)specifier;
}
