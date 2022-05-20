/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 16:41:58 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/18 23:27:23 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	ft_word_count(char *str, char charset)
{
	long long	count;

	count = 0;
	while (*str)
	{
		if (*str != charset)
		{
			++count;
			while (*str && *str != charset)
				++str;
		}
		if (*str != 0)
			str++;
	}
	return (count);
}
