/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:41:33 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/29 02:19:24 by louismauj        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * count);
	if (!str)
		return (0);
	i = 0;
	while (i != size * count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	i = 0;
	if (!s)
		return (0);
	if (len < ft_strlen(s))
		str = ft_calloc(sizeof(char), len + 1);
	else
		str = ft_calloc(sizeof(char), (ft_strlen(s + start) + 1));
	if (!str)
		return (0);
	if (start < ft_strlen(s))
	{
		i = 0;
		while (i < len && s[start])
		{
			str[i] = s[start];
			i++;
			start++;
		}
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;

	if (!s1 || !s2)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlen(str), s2);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)s + i);
		i++;
	}
	return (0);
}
