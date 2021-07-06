/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 08:28:27 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/05 17:58:02 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manage_u_precision(t_arg *arg_struct)
{
	int		len;
	char	*str;

	if (arg_struct->precision > -1)
	{
		str = arg_struct->str;
		len = arg_struct->precision - ft_strlen(str);
		if (arg_struct->precision == 0 && str[0] == '0')
			arg_struct->str[0] = '\0';
		else if (len > 0 && arg_struct->is_negative)
		{
			ft_addnfix(&(arg_struct->str), '0', len, 1);
			ft_addnfix(&(arg_struct->str), '-', 1, 1);
		}
		else if (len > 0)
			ft_addnfix(&(arg_struct->str), '0', len, 1);
		else if (len <= 0 && arg_struct->is_negative)
			ft_addnfix(&(arg_struct->str), '-', 1, 1);
		else
			arg_struct->str = ft_memmove(arg_struct->str,
					arg_struct->str, arg_struct->precision);
	}
}

int	get_u_zero_field_len(t_arg *arg_struct)
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

void	manage_u_zeros_width(t_arg *arg_struct)
{
	int	len;

	if (arg_struct->fieldwidth != -1 && arg_struct->flags->has_zeroflag)
	{
		len = get_u_zero_field_len(arg_struct);
		if (len > 0)
			ft_addnfix(&(arg_struct->str), '0', len, 1);
		if (arg_struct->is_negative)
			ft_addnfix(&(arg_struct->str), '-', 1, 1);
	}
}

int	manage_u_width(t_arg *arg_struct)
{
	int	len;
	int	str_size;

	len = 0;
	str_size = 0;
	if (arg_struct->fieldwidth != -1)
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
	str_size = ft_strlen(arg_struct->str);
	return (str_size);
}

int	print_u(t_arg *arg_struct)
{
	int	len;
	int	str_size;

	len = 0;
	str_size = 0;
	manage_u_precision(arg_struct);
	manage_u_zeros_width(arg_struct);
	str_size += manage_u_width(arg_struct);
	ft_putstr(arg_struct->str);
	if (arg_struct->fieldwidth < 0)
	{
		len = (arg_struct->fieldwidth * (-1)) - str_size;
		while (len > 0)
		{
			str_size += ft_putchar(' ');
			len--;
		}
	}
	return (str_size);
}
