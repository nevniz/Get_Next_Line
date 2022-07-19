/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:13:57 by llawrenc          #+#    #+#             */
/*   Updated: 2021/11/16 11:49:38 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *saved_read_line)
{
	char	*buffer;
	int		count;

	count = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(saved_read_line, '\n')) && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		saved_read_line = modified_ft_strjoin(saved_read_line, buffer);
	}
	free(buffer);
	return (saved_read_line);
}

char	*get_next_line(int fd)
{
	static char	*saved_read_line;
	char		*output_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	saved_read_line = ft_read_line(fd, saved_read_line);
	if (!saved_read_line)
		return (NULL);
	output_line = ft_output_line(saved_read_line);
	saved_read_line = ft_cut_read_line(saved_read_line);
	return (output_line);
}
