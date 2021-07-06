/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:24:38 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 17:56:00 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_s_precision(t_arg *arg_struct)
{
	int		len;
	char	*str;

	if (arg_struct->precision > -1)
	{
		str = arg_struct->str;
		len = arg_struct->precision - ft_strlen(str);
		if (len <= 0)
		{
			arg_struct->str = ft_strndup(str, arg_struct->precision);
			if (str)
				free(str);
		}
	}
}

int	manage_s_width(t_arg *arg_struct)
{
	int	len;
	int	str_size;

	len = 0;
	str_size = 0;
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
			else if (arg_struct->type != is_unum)
				ft_addnfix(&(arg_struct->str), ' ', len, 1);
		}
	}
	str_size = ft_strlen(arg_struct->str);
	return (str_size);
}

int	print_s(t_arg *arg_struct)
{
	int	str_size;

	str_size = 0;
	manage_s_precision(arg_struct);
	str_size += manage_s_width(arg_struct);
	if (arg_struct->fieldwidth < -1)
	{
		str_size = ft_putstr(arg_struct->str);
		while (arg_struct->fieldwidth < (int)(ft_strlen(arg_struct->str) * -1))
		{
			str_size += ft_putchar(' ');
			arg_struct->fieldwidth++;
		}
	}
	else
		str_size = ft_putstr(arg_struct->str);
	return (str_size);
}
