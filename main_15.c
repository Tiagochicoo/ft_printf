/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:32:03 by tpereira          #+#    #+#             */
/*   Updated: 2021/06/30 19:28:51 by tpereira         ###   ########.fr       */
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

	write(1, "ft_printf:|", 11);
	len = ft_printf(" *%*.*d* *%*.*d* ", -6, 2, 102, 10, 21, 101);
	printf("|\nprintf:   |");
	len2 = printf(" *%*.*d* *%*.*d* ", -6, 2, 102, 10, 21, 101);
	printf("|\n");
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
