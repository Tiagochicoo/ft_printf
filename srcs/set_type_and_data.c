/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type_and_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:28:39 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/26 15:18:59 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_type(t_arg *arg_struc)
{
	char	s;

	s = arg_struc->specifier;
	if (s == 'c')
		arg_struc->type = is_char;
	else
		arg_struc->type = is_null;
}

void	set_data(t_arg *arg_struct, va_list *args)
{
	void	(*set_datatype[8])(t_arg *, va_list *);

	set_datatype[is_char] = set_char;
	set_datatype[arg_struct->type](arg_struct, args);
}