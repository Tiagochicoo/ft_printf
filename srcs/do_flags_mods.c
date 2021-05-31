/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags_mods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:49:57 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/31 11:53:18 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
