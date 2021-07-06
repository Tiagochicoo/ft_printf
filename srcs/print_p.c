/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:36:22 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 17:53:47 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_p_precision(t_arg *arg_struct)
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
			if (arg_struct->str)
				free(str);
		}
	}
}

int	manage_p_width(t_arg *arg_struct)
{
	int	str_size;

	str_size = 0;
	if (arg_struct->fieldwidth <= 0 || arg_struct->flags->has_minusflag)
	{
		if (arg_struct->flags->has_minusflag && arg_struct->fieldwidth >= 0)
			arg_struct->fieldwidth *= -1;
		str_size = ft_putstr("0x");
		str_size += ft_putstr(arg_struct->str);
		arg_struct->fieldwidth += (ft_strlen(arg_struct->str) + 1);
		while (arg_struct->fieldwidth++ < -1)
			str_size += ft_putchar(' ');
	}
	else if (arg_struct->fieldwidth > 1)
	{
		while (arg_struct->fieldwidth-- > ((int)ft_strlen(arg_struct->str) + 2))
			str_size += ft_putchar(' ');
		str_size += ft_putstr("0x");
		str_size += ft_putstr(arg_struct->str);
	}
	return (str_size);
}

int	print_p(t_arg *arg_struct)
{
	int	str_size;

	str_size = 0;
	manage_p_precision(arg_struct);
	str_size += manage_p_width(arg_struct);
	return (str_size);
}
