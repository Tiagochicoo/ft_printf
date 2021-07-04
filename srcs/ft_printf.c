/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:22:10 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/04 17:40:07 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_args(t_arg *arg_struct)
{
	int	str_size;

	str_size = 0;
	if (arg_struct->specifier == 'c')
		str_size = print_c(arg_struct);
	if (arg_struct->specifier == 's')
		str_size = print_s(arg_struct);
	if (arg_struct->specifier == 'p')
		str_size = print_p(arg_struct);
	if (arg_struct->specifier == 'd' || arg_struct->specifier == 'i')
	str_size = print_di(arg_struct);
	// if (arg_struct.specifier == 'u')
	// str_size = print_u(arg_struct);
	// if (arg_struct.specifier == 'x')
	// str_size = print_x(arg_struct);
	// if (arg_struct.specifier == 'X')
	// str_size = print_xx(arg_struct);
	// if (arg_struct.specifier == '%')
	// str_size = print_(arg_struct);
	
	return (str_size);
}

int	write_arg(t_arg arg_struct)
{
	int	str_size;

	if (arg_struct.type == is_char && arg_struct.str == NULL)
	{
		str_size = ft_putchar(0);
		if (arg_struct.fieldwidth < -1)
		{
			while (arg_struct.fieldwidth < -1)
			{
				str_size += ft_putchar(' ');
				arg_struct.fieldwidth++;
			}
		}
		else
		{
			while (arg_struct.fieldwidth > 1)
			{
				str_size += ft_putchar(' ');
				arg_struct.fieldwidth--;
			}
		}
	}
	else if (arg_struct.is_invalid == 1)
		str_size = 0;
	else if (ft_strlen(arg_struct.str) == 1 && arg_struct.type != is_unum)
		str_size = ft_putchar(*arg_struct.str);
	else if (arg_struct.type == is_string && arg_struct.fieldwidth != -1)
	{
		if (arg_struct.fieldwidth < 0)
		{
			str_size = ft_putstr(arg_struct.str);
			while (arg_struct.fieldwidth < (int)(ft_strlen(arg_struct.str) * -1))
			{
				str_size += ft_putchar(' ');
				arg_struct.fieldwidth++;
			}
		}
		else
			str_size = ft_putstr(arg_struct.str);
	}
	else if (arg_struct.specifier == 'p' && arg_struct.fieldwidth <= 0)
	{
		str_size = ft_putstr("0x");
		str_size += ft_putstr(arg_struct.str);
		while (arg_struct.fieldwidth < -4)
		{
			str_size += ft_putchar(' ');
			arg_struct.fieldwidth++;
		}
	}
	else
		str_size = ft_putstr(arg_struct.str);
	if (arg_struct.str && ft_strlen(arg_struct.str) == 1
		&& arg_struct.fieldwidth < -1)
	{
		while (arg_struct.fieldwidth < -1)
		{
			str_size += ft_putchar(' ');
			arg_struct.fieldwidth++;
		}
	}
	return (str_size);
}

int	print_data(char *format_copy, va_list *args)
{
	int		printed_chars;
	char	*input;
	t_arg	arg_struct;

	printed_chars = 0;
	while (1)
	{
		input = read_str(&format_copy);
		if (!input)
			break ;
		if (input[0] == '%')
		{
			arg_struct = read_arg(input, args);
			printed_chars += write_args(&(arg_struct));
			free_struct(&arg_struct);
		}
		else
			printed_chars += ft_putstr(input);
		free(input);
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*format_copy;
	int		printed_chars;

	printed_chars = 0;
	if (!format)
		return (0);
	format_copy = ft_strdup(format);
	va_start(args, format);
	printed_chars = print_data(format_copy, &args);
	free(format_copy);
	va_end(args);
	return (printed_chars);
}
