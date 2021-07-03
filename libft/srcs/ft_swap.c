/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 14:50:17 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/03 14:54:45 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_swap(char *str, size_t i)
{
	char	temp;
	size_t	j;
	size_t	n;

	j = 0;
	n = i;
	while (j < ((n + 1) / 2))
	{
		temp = str[j];
		str[j++] = str[i];
		str[i--] = temp;
	}
	str[n + 1] = 0;
	return (str);
}