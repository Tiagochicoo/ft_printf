/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_escape.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:05:00 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/04 14:01:41 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    manage_escape_precision(t_arg *arg_struct)
{
    if (arg_struct->precision > -1)
        ft_memmove(arg_struct->str, arg_struct->str, arg_struct->precision);
}

int    manage_escape_width(t_arg *arg_struct)
{
    int		len;
    int     str_size;

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
				while (arg_struct->fieldwidth > 1)
                {
                    str_size += ft_putchar(' ');
                    arg_struct->fieldwidth--;
                }
			}
        }
		else if (len < 0)
		{
			while (arg_struct->fieldwidth < -1)
			{
				ft_addnfix(&(arg_struct->str), ' ', 1, 2);
				arg_struct->fieldwidth++;
			}
		}
    }
    return (str_size);
}

int		print_escape(t_arg *arg_struct)
{
    int str_size;

    str_size = 0;
    manage_escape_precision(arg_struct);
    str_size += manage_escape_width(arg_struct);

    if (arg_struct->str == NULL)
    {
        str_size = ft_putchar(0);
		if (arg_struct->fieldwidth < -1)
		{
			while (arg_struct->fieldwidth < -1)
			{
				str_size += ft_putchar(' ');
				arg_struct->fieldwidth++;
			}
		}
		else
		{
			while (arg_struct->fieldwidth > 1)
			{
				str_size += ft_putchar(' ');
				arg_struct->fieldwidth--;
			}
		}
    }
    else
        str_size += ft_putstr(arg_struct->str);
    return (str_size);
}