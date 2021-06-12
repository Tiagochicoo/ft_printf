/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type_and_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:28:39 by tpereira          #+#    #+#             */
/*   Updated: 2021/06/12 14:55:24 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_type(t_arg *arg_struc)
{
	char	s;

	s = arg_struc->specifier;
	if (s == 'c')
		arg_struc->type = is_char;
	else if (s == 's')
		arg_struc->type = is_string;
	else if (s == 'p')
		arg_struc->type = is_unum;
	else if (s == 'd')
		arg_struc->type = is_snum;
	else
		arg_struc->type = is_null;
}

void	set_unum(t_arg *arg_struct, va_list *args)
{
	size_t	unum;

	if (arg_struct->specifier == 'p')
		unum = va_arg(*args, size_t);
	arg_struct->data = &unum;
	set_base(arg_struct);
	arg_struct->str = ft_itoabase_umax(unum, arg_struct->base);
}

void	set_snum(t_arg *arg_struct, va_list *args)
{
	intmax_t	snum;

	if (!arg_struct->modifiers)
		snum = va_arg(*args, int);
	else if (ft_countletter(arg_struct->modifiers, 'l') == 2)
		snum = va_arg(*args, long long);
	else if (ft_countletter(arg_struct->modifiers, 'l') == 1)
		snum = va_arg(*args, long);
	else if (ft_countletter(arg_struct->modifiers, 'h') == 2)
		snum = (char)va_arg(*args, int);
	else if (ft_countletter(arg_struct->modifiers, 'h') == 1)
		snum = (short)va_arg(*args, int);
	else
		snum = va_arg(*args, intmax_t);
	arg_struct->data = &snum;
	set_is_negative(arg_struct);
	arg_struct->str = ft_itoabase_umax(snum, arg_struct->base);
}

void	set_data(t_arg *arg_struct, va_list *args)
{
	void	(*set_datatype[8])(t_arg *, va_list *);

	set_datatype[is_char] = set_char;
	set_datatype[is_string] = set_string;
	set_datatype[is_unum] = set_unum;
	set_datatype[is_snum] = set_snum;
	set_datatype[arg_struct->type](arg_struct, args);
}