/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 20:40:10 by jmiranda          #+#    #+#             */
/*   Updated: 2023/07/12 13:21:41 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_buff(int fd, char *line, int *nl, int *end)
{
	ssize_t		rd_ret;
	static char	str[30][100000000];

	while (str[fd][*end] != '\0')
		(*end)++;
	while (ft_strchr(str[fd], '\n', nl, end) == NULL)
	{
		rd_ret = read(fd, str[fd] + *end, BUFFER_SIZE);
		*end += rd_ret;
		if (rd_ret == -1)
		{
			str[fd][0] = '\0';
			return (NULL);
		}
		if (rd_ret == 0)
			break ;
		str[fd][*end] = '\0';
	}
	if (str[fd][*nl] == '\n')
		(*nl)++;
	line = ft_strdup(str[fd], nl);
	ft_memcpy(str[fd], str[fd] + *nl, *end - *nl);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	int		end;
	int		nl;

	end = 0;
	nl = 0;
	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0 || fd > 29)
		return (NULL);
	line = ft_read_buff(fd, line, &nl, &end);
	if (!line)
		return (NULL);
	return (line);
}
