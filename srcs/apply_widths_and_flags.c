/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_widths_and_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:12:17 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/26 14:24:17 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_width(t_arg *arg_struct)
{
	int		len;

	len = 0;
	if (arg_struct->fieldwidth != -1 && arg_struct->flags->has_zeroflag == 0)
	{
		if (arg_struct->str)
			len = arg_struct->fieldwidth - ft_strlen(arg_struct->str);
		if (len > 0)
		{
			if (arg_struct->flags->has_minusflag)
				ft_addnfix(&(arg_struct->str), ' ', len, 2);
			else if (arg_struct->flags->has_starflag)
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
			else
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
		}
	}
}

void	apply_widths_and_flags(t_arg *arg_struct)
{
	//manage_precision(arg_struct);
	manage_width(arg_struct);
}