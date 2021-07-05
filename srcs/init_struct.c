/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:42:52 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 12:37:54 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*new_flags(void)
{
	t_flag	*flags;

	flags = (t_flag *)malloc(sizeof(t_flag));
	if (!flags)
		return (NULL);
	flags->has_minusflag = 0;
	flags->has_zeroflag = 0;
	flags->has_starflag = 0;
	flags->has_hashflag = 0;
	flags->has_spaceflag = 0;
	flags->has_plusflag = 0;
	return (flags);
}

void	init_struct(t_arg *arg)
{
	arg->type = is_null;
	arg->flags = new_flags();
	arg->fieldwidth = -1;
	arg->precision = -1;
	arg->specifier = 0;
	arg->is_invalid = 0;
	arg->is_negative = 0;
	arg->base = 10;
	arg->data = NULL;
	arg->str = NULL;
}

void	set_struct(char *input, t_arg *arg_struct, va_list *args)
{
	input++;
	set_flags(&input, arg_struct);
	set_width(&input, arg_struct, args);
	set_precision(&input, arg_struct, args);
	set_specifier(&input, arg_struct);
	set_type(arg_struct);
	set_data(arg_struct, args);
	clean_flags(arg_struct);
}

void	free_struct(t_arg *arg_struct)
{
	free(arg_struct->flags);
	arg_struct->flags = NULL;
	if (arg_struct->str)
	{
		free(arg_struct->str);
		arg_struct->str = NULL;
	}
}
