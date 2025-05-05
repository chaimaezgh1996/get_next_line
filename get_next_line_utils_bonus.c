/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czghoumi <czghoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:59:44 by czghoumi          #+#    #+#             */
/*   Updated: 2024/12/19 05:17:24 by czghoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_bonus(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_bonus(const char *s1)
{
	char	*ptr;
	int		i;

	ptr = malloc(ft_strlen_bonus((char *)s1) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_copy_bonus(char *dest, const char *src, size_t src_len)
{
	size_t	i;

	i = 0;
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ptr;

	len1 = ft_strlen_bonus(s1);
	len2 = ft_strlen_bonus(s2);
	if (!s1 && !s2)
		return (NULL);
	if (s2 == NULL)
		return (free(s1), ft_strdup_bonus(s1));
	if (s1 == NULL)
		return (ft_strdup_bonus(s2));
	ptr = malloc(len1 + len2 + 1);
	if (ptr == NULL)
		return (free(s1), NULL);
	ft_copy_bonus(ptr, s1, len1);
	ft_copy_bonus(ptr + len1, s2, len2);
	ptr[len1 + len2] = '\0';
	free(s1);
	return (ptr);
}
