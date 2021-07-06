/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:32:03 by tpereira          #+#    #+#             */
/*   Updated: 2021/07/06 21:01:00 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "./includes/ft_printf.h"
#define INT_MIN -2147483648
#define UINT_MAX 2147483647

// %[flags][width][.precision][length]specifier
int main(void)
{
	int len, len2;

	len = write(1, "ft_printf:|", 11);
	len = ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 2, 6, 102, 21, 10, -101);
	printf("|\nprintf:   |");
	len2 = printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 2, 6, 102, 21, 10, -101);
	printf("|\n");
	if (len != len2)
	{
		int message = len - len2;
		printf("Lengths differ -> %d\n",message);
		return (1);
	}
	else
		printf("All good! \n");
	return (0);
}
