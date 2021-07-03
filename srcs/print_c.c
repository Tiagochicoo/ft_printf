/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:05:00 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/03 17:40:35 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    manage_c_precision(t_arg *arg_struct)
{
    int		len;
	char	*str;
    
    if (arg_struct->precision > -1)
    {
        str = arg_struct->str;
		len = arg_struct->precision - ft_strlen(str);
        
        ft_memmove(arg_struct->str, arg_struct->str, arg_struct->precision);
    }
}

int    manage_c_width(t_arg *arg_struct)
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
				while (arg_struct->fieldwidth > 1)
                {
                    str_size += ft_putchar(' ');
                    arg_struct->fieldwidth--;
                }
            return (str_size);
        }
    }
    return (str_size);
}

int		print_c(t_arg *arg_struct)
{
    int str_size;

    str_size = 0;
    manage_c_precision(arg_struct);
    str_size += manage_c_width(arg_struct);

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