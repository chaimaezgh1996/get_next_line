/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:59:33 by czghoumi          #+#    #+#             */
/*   Updated: 2024/12/19 05:17:17 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_found_bonus(const char *str, char c)
{
	while (*str) 
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_read_bonus(char *str, char *buffer, int fd)
{
	int	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		str = ft_strjoin_bonus(str, buffer);
		if (!str)
			return (free(str), str = NULL, NULL);
		if (ft_found_bonus(str, '\n') == 1)
			break ;
	}
	return (str);
}

char	*ft_char_front_bonus(char *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (s[len] == '\n')
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_char_back_bonus(char *s)
{
	int		i;
	int		len;
	int		remaining_len;
	char	*str;

	i = 0;
	len = 0;
	remaining_len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	if (s[len] == '\0')
		return (NULL);
	len++;
	while (s[len + remaining_len] != '\0')
		remaining_len++;
	str = malloc(remaining_len + 1);
	if (!str)
		return (NULL);
	while (i < remaining_len)
	{
		str[i] = s[len + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*tmp;
	static char	*str[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str[fd]), str[fd] = NULL, NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (free(str[fd]), str[fd] = NULL, NULL);
	str[fd] = ft_read_bonus(str[fd], buffer, fd);
	free(buffer);
	if (str[fd] == NULL)
		return (free(str[fd]), str[fd] = NULL, NULL);
	if (str[fd][0] == '\0')
		return (free(str[fd]), str[fd] = NULL, NULL);
	line = ft_char_front_bonus(str[fd]);
	if (!line)
		return (free(str[fd]), str[fd] = NULL, NULL);
	tmp = ft_char_back_bonus(str[fd]);
	if (!tmp)
		return (free(str[fd]), str[fd] = NULL, line);
	free(str[fd]);
	str[fd] = tmp;
	return (line);
}
