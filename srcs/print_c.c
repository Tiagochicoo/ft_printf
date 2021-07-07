/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:05:00 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/07 22:42:18 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_c_precision(t_arg *arg_struct)
{
	if (arg_struct->precision > -1)
		ft_memmove(arg_struct->str, arg_struct->str, arg_struct->precision);
}

int	manage_c_width(t_arg *arg_struct)
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
			else
			{
				while (arg_struct->fieldwidth-- > 1)
					str_size += ft_putchar(' ');
			}
		}
		else if (len < 0)
			while (arg_struct->fieldwidth++ < -1)
				ft_addnfix(&(arg_struct->str), ' ', 1, 2);
	}
	return (str_size);
}

void	check_flags(t_arg *arg_struct)
{
	if (arg_struct->fieldwidth > 0)
		if (arg_struct->flags->has_starflag && arg_struct->flags->has_minusflag)
			arg_struct->fieldwidth *= -1;
}

int	print_c(t_arg *arg_struct)
{
	int	str_size;

	str_size = 0;
	manage_c_precision(arg_struct);
	str_size += manage_c_width(arg_struct);
	if (arg_struct->str == NULL)
	{
		check_flags(arg_struct);
		if (arg_struct->fieldwidth < 0)
		{
			str_size += ft_putchar(0);
			while (arg_struct->fieldwidth++ < -1)
				str_size += ft_putchar(' ');
		}
		else
		{
			while (arg_struct->fieldwidth-- > 1)
				str_size += ft_putchar(' ');
			str_size += ft_putchar(0);
		}
	}
	else
		str_size += ft_putstr(arg_struct->str);
	return (str_size);
}
