/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_chars_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:46:53 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/26 10:53:48 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_char(t_arg *arg_struct, va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	arg_struct->data = &c;
	if (c)
		arg_struct->str = ft_chrtostr(c);
}