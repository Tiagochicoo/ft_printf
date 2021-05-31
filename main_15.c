/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:32:03 by tpereira          #+#    #+#             */
/*   Updated: 2021/05/31 11:25:58 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./includes/ft_printf.h"
#include "colors.h"

// %[flags][width][.precision][length]specifier
int main(void)
{
	int len, len2;

	len = ft_printf(" %*.s %.1s ", 10, "123", "4567");
	printf("\n");
	len2 = printf(" %*.s %.1s ", 10, "123", "4567");
	printf("\n");
	if (len != len2)
	{
		int message = len - len2;
		printf("%s%sLengths differ -> %d%s\n", RED, WHITE_BG, message, CLEAR);
		return (1);
	}
	else
		printf("%s%sAll good! \n", GREEN, CLEAR);
	return (0);
}
