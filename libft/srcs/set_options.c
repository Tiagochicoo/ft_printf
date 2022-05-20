/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:41:21 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/18 23:28:35 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_base(t_arg *ptr_arg_struct)
{
	char	specifier;

	specifier = ptr_arg_struct->specifier;
	if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		ptr_arg_struct->base = 16;
	else if (specifier == 'b' || specifier == 'B')
		ptr_arg_struct->base = 2;
	else if (specifier == 'o' || specifier == 'O')
		ptr_arg_struct->base = 8;
	else
		ptr_arg_struct->base = 10;
}

void	set_is_negative(t_arg *ptr_arg_struct)
{
	char	specifier;

	specifier = ptr_arg_struct->specifier;
	if ((specifier == 'd' || specifier == 'i')
		&& *(intmax_t *)(ptr_arg_struct->data) < 0)
	{
		ptr_arg_struct->is_negative = 1;
		*(intmax_t *)(ptr_arg_struct->data) *= -1;
	}
}
