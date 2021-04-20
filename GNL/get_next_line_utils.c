/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:41:33 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/20 14:02:08 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * count);
	if (!str)
		return (NULL);
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
	unsigned int	i;

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
	int			i;
	
	i = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = ft_strdup(s2);
		return ((char *)s1);
	}	
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2 != '\n')
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
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
	return (NULL);
}
