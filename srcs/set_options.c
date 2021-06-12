/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 09:33:52 by tpereira          #+#    #+#             */
/*   Updated: 2021/06/11 17:27:31 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_base(t_arg *arg_struct)
{
	char	s;

	s = arg_struct->specifier;
	if (s == 'p')
		arg_struct->base = 16;
}

void	set_is_negative(t_arg *arg_struct)
{
	char	s;

	s = arg_struct->specifier;
	if ((s == 'd' || s == 'i') && (arg_struct->data != NULL))
	{
		arg_struct->is_negative = 1;
		*(intmax_t *)(arg_struct->data) *= -1;
	}
}