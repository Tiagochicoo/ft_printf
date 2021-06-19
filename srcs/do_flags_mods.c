/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags_mods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:49:57 by tpereira          #+#    #+#             */
/*   Updated: 2021/06/19 12:37:40 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_zero_field_len(t_arg *arg_struct)
{
	int	len;

	len = arg_struct->fieldwidth - ft_strlen(arg_struct->str);
	if (arg_struct->flags->has_spaceflag || arg_struct->flags->has_plusflag
		|| arg_struct->is_negative)
		len = len - 1;
	if (arg_struct->flags->has_hashflag && arg_struct->base == 8)
		len = len - 2;
	if (arg_struct->flags->has_hashflag && arg_struct->base == 16)
		len = len - 2;
	return (len);
}

void	manage_zero_width(t_arg *arg_struct)
{
	int	len;

	if (arg_struct->fieldwidth != -1 && arg_struct->flags->has_zeroflag)
	{
		len = get_zero_field_len(arg_struct);
		if (len > 0)
			ft_addnfix(&(arg_struct->str), '0', len, 1);
	}
}
