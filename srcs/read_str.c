/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:44:20 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/07 20:46:56 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_len_to_spec(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

int	get_var_len(char *str)
{
	int	i;

	i = 1;
	while (!ft_strrchr(CONVERSIONS, str[i]))
		i++;
	if (str[i] == '%' && str[i + 1] == '%')
		i = 1;
	return (i + 1);
}

char	*read_str(char **str)
{
	int		len;
	char	*str_block;

	len = 0;
	if (**str == '\0')
		return (0);
	else if (**str == '%')
		len = get_var_len(*str);
	else
		len = get_len_to_spec(*str, '%');
	str_block = ft_strsub(*str, 0, len);
	*str += len;
	return (str_block);
}
