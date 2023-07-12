/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:23:43 by jmiranda          #+#    #+#             */
/*   Updated: 2023/07/12 13:36:19 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c, int *nl, int *end)
{
	while (*(str + *nl) != '\0' && *nl != *end)
	{
		if (*(str + *nl) == (char)c)
			return ((char *)str);
		(*nl)++;
	}
	if (*(str + *nl) == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *str, int *nl)
{
	char	*line;
	int		i;

	if (str[0] == '\0')
		return (NULL);
	i = 0;
	line = (char *)malloc(sizeof(char) * (*nl + 1));
	if (!line)
		return (NULL);
	while (i < *nl)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	*ft_memcpy(void *begin, const void *remains, size_t n)
{
	size_t	i;

	i = 0;
	if (!begin && !remains)
		return (NULL);
	while (n--)
	{
		*((unsigned char *)begin + i) = *((unsigned char *)remains + i);
		i++;
	}
	*((unsigned char *)begin + i) = '\0';
	return (begin);
}
