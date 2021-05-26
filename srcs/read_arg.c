/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:38:47 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/26 11:11:48 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg read_arg(char **input, t_arg *args)
{
	t_arg	arg_struct;

	init_struct(&arg_struct);
	set_struct(input, &arg_struct, args);
	apply_widths_and_flags(&arg_struct);
}