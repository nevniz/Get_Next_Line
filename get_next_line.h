/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llawrenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:59:03 by llawrenc          #+#    #+#             */
/*   Updated: 2021/11/16 12:15:32 by llawrenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *saved_read_line);
char	*ft_output_line(char *saved_read_line);
char	*ft_cut_read_line(char	*saved_read_line);
char	*ft_strchr(char *s, int c);
char	*modified_ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
