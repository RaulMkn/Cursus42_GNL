/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:39:57 by rmakende          #+#    #+#             */
/*   Updated: 2024/08/14 16:02:56 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	s_len;

	s_len = ft_strlen(s);
	i = 0;
	if (!s)
		return (0);
	if (start > s_len)
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (s_len - start < len)
		len = s_len - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < s_len && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	char		*duplicate;
	size_t		size;
	size_t		i;

	size = ft_strlen(str) + 1;
	duplicate = (char *)malloc(size * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		duplicate[i] = str[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
