/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 08:59:57 by tpereira          #+#    #+#             */
/*   Updated: 2022/05/17 23:34:06 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	finish(char buffer[], int count[], char **str_arr)
{
	buffer[count[1]] = '\0';
	count[2] = sizeof(char) * (ft_strlen(buffer) + 1);
	str_arr[count[0]] = malloc(count[2]);
	ft_strlcpy(str_arr[count[0]], buffer, ft_strlen(buffer) + 1);
	return ('\0');
}

void	str_alloc(const char *str, char *charset, int i, char **str_arr)
{
	int		count[4];
	char	buffer[1638954];

	count[0] = 0;
	count[3] = ft_strlen(str);
	while (i < count[3])
	{
		while (i < count[3])
		{
			if (ft_strchr(charset, str[i]) == NULL)
				break ;
			i++;
		}
		count[1] = 0;
		while (i < count[3])
		{
			if (ft_strchr(charset, str[i]) != NULL)
				break ;
			buffer[count[1]] = str[i++];
			count[1] += 1;
		}
		if (count[1] > 0)
		{
			buffer[count[1]] = finish(buffer, count, str_arr);
			count[0] += 1;
		}
	}
}

char	**ft_split(char const *str, char *charset)
{
	int		len;
	int		count;
	int		i;
	int		j;
	char	**str_arr;

	len = ft_strlen(str);
	count = 0;
	i = 0;
	while (i < len)
	{
		while (i < len)
			if (ft_strchr(charset, str[i++]) == NULL)
				break ;
		j = i;
		while (i < len)
			if (ft_strchr(charset, str[i++]) != NULL)
				break ;
		if (i > j)
			count += 1;
	}
	str_arr = malloc(sizeof(char *) * (count + 1));
	str_arr[count] = NULL;
	str_alloc(str, charset, 0, str_arr);
	return (str_arr);
}
