/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:22:10 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/06 19:57:28 by tpereira         ###   ########.fr       */
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
	if (arg_struct->specifier == 'u')
		str_size = print_u(arg_struct);
	if (arg_struct->specifier == 'x' || arg_struct->specifier == 'X')
		str_size = print_x(arg_struct);
	if (arg_struct->specifier == '%')
		str_size = print_escape(arg_struct);
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
