/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:33:52 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/07 17:49:10 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_base(t_arg *arg_struct)
{
	char	s;

	s = arg_struct->specifier;
	if (s == 'p' || s == 'x' || s == 'X')
		arg_struct->base = 16;
}

void	set_is_negative(t_arg *arg_struct)
{
	char	s;

	s = arg_struct->specifier;
	if ((s == 'd' || s == 'i' || s == 'x') && *(intmax_t *)arg_struct->data < 0)
	{
		arg_struct->is_negative = 1;
	}
}
