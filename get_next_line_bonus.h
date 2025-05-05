/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:59:36 by czghoumi          #+#    #+#             */
/*   Updated: 2024/12/19 05:15:54 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef MAX_FD
#  define MAX_FD 10240
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_bonus(const char *str);
char	*ft_strjoin_bonus(char *s1, char *s2);
int		ft_found_bonus(const char *str, char c);
char	*ft_strdup_bonus(const char *s1);
char	*ft_char_front_bonus(char *s);
char	*ft_read_bonus(char *str, char *buffer, int fd);
char	*ft_char_back_bonus(char *s);
void	ft_copy_bonus(char *dest, const char *src, size_t src_len);
#endif
