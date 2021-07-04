/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:38:47 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/04 16:34:42 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	read_arg(char *input, va_list *args)
{
	t_arg	arg_struct;

	init_struct(&arg_struct);
	set_struct(input, &arg_struct, args);
	//apply_widths_and_flags(&arg_struct);
	return (arg_struct);
}
