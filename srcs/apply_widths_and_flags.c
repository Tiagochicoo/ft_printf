/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_widths_and_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:12:17 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/31 11:43:57 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_precision(t_arg *arg_struct)
{
	int		len;
	char	*str;

	if (arg_struct->precision != -1)
	{
		str = arg_struct->str;
		len = arg_struct->precision - ft_strlen(str);
		if (arg_struct->type == is_string && len < 0)
		{
			if (arg_struct->str == ft_strndup(str, arg_struct->precision))
				free(str);
		}
		else if (arg_struct->type == is_unum || arg_struct->type == is_snum)
		{
			if (arg_struct->precision == 0 && str[0] == '0' && str[1] == '\0')
				arg_struct->str[0] = '\0';
			else if (len > 0)
				ft_addnfix(&(arg_struct->str), '0', len, 1);
		}
	}
}

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
	manage_precision(arg_struct);
	manage_width(arg_struct);
}