/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_widths_and_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:12:17 by tpereira          #+#    #+#             */
/*   Updated: 2021/06/30 19:18:52 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_precision(t_arg *arg_struct)
{
	int		len;
	char	*str;

	if (arg_struct->precision > -1)
	{
		str = arg_struct->str;
		len = arg_struct->precision - ft_strlen(str);
		if (arg_struct->type == is_string && len <= 0)
		{
			if ((arg_struct->str = ft_strndup(str, arg_struct->precision)))
				free(str);
		}
		else if (arg_struct->type == is_unum || arg_struct->type == is_snum)
		{
			if (arg_struct->precision == 0 && str[0] == '0' && str[1] == '\0')
				arg_struct->str[0] = '\0';
			else if (len > 0 && arg_struct->is_negative == 1
				&& arg_struct->str[0] != '0')
			{
				ft_addnfix(&(arg_struct->str), '0', len, 1);
				ft_addnfix(&(arg_struct->str), '-', 1, 1);
			}
			else if (len > 0 && arg_struct->is_negative == 0
				&& arg_struct->type == is_unum)
				ft_addnfix(&(arg_struct->str), '0', len, 1);
			else if (len > 0 && arg_struct->is_negative == 1)
				ft_addnfix(&(arg_struct->str), '0', len, 1);
			else if (len > 0 && arg_struct->precision > len && arg_struct->flags->has_minusflag == 1)
				ft_addnfix(&(arg_struct->str), '0', arg_struct->precision - (len), 1);
			else if (arg_struct->precision > len && arg_struct->is_negative)
			{
				ft_addnfix(&(arg_struct->str), '-', 1, 1);
				ft_addnfix(&(arg_struct->str), '0',
					arg_struct->precision - 1, 1);
			}
			else if (len > 0 && arg_struct->precision > len)
				ft_addnfix(&(arg_struct->str), '0', len, 1);
			else
				arg_struct->str = ft_memmove(arg_struct->str, arg_struct->str, arg_struct->precision);
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
			if (arg_struct->type == is_unum && arg_struct->flags->has_minusflag)
			{
				ft_addnfix(&(arg_struct->str), 'x', 1, 1);
				ft_addnfix(&(arg_struct->str), '0', 1, 1);
				len -= 2;
				ft_addnfix(&(arg_struct->str), ' ', len, 2);
			}
			else if (arg_struct->type == is_unum
				&& !arg_struct->flags->has_minusflag)
			{
				ft_addnfix(&(arg_struct->str), 'x', 1, 1);
				ft_addnfix(&(arg_struct->str), '0', 1, 1);
				len -= 2;
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
			}
			else if (arg_struct->flags->has_minusflag)
				ft_addnfix(&(arg_struct->str), ' ', len, 2);
			else if (arg_struct->flags->has_starflag)
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
			else if (arg_struct->type != is_unum)
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
		}
	}
}

void	apply_widths_and_flags(t_arg *arg_struct)
{
	manage_precision(arg_struct);
	manage_zero_width(arg_struct);
	manage_width(arg_struct);
}
