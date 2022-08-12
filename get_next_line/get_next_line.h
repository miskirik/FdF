/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miskirik <miskirik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 01:40:47 by miskirik          #+#    #+#             */
/*   Updated: 2022/08/11 04:56:29 by miskirik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

size_t	f_strlen(char *str);
char	*ft_buff(int fd, char *str);
char	*get_next_line(int fd);
char	*strjoin(char *str, char *buff);
char	*f_strchr(char *str, int c);
char	*ft_get_line(char *str);
char	*ft_last_str(char *str);
#endif
