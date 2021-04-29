/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:55:43 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/29 02:24:47 by louismauj        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	str = ft_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = ((char *)src)[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	read_line(char **str, int *sizeread, char buf[BUFFER_SIZE], int fd)
{
	char	*temp;

	*sizeread = 1;
	if (*str == 0)
		*str = ft_calloc(sizeof(char), 1);
	while (ft_strchr(*str, '\n') == 0 && *sizeread > 0)
	{
		*sizeread = read(fd, buf, BUFFER_SIZE);
		buf[*sizeread] = 0;
		temp = ft_strjoin(*str, buf);
		free(*str);
		*str = ft_strdup(temp);
		free(temp);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*str = 0;
	int			sizeread;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;

	read_line(&str, &sizeread, buf, fd);
	if (sizeread == 0)
	{
		*line = ft_strdup(str);
		free(str);
		str = 0;
		return (0);
	}
	if (sizeread > 0)
	{
		*line = ft_substr(str, 0, (ft_strchr(str, '\n') - str));
		temp = ft_strdup(str + ft_strlen(*line) + 1);
		free(str);
		str = temp;
		return (1);
	}
	if (fd == -1 && BUFFER_SIZE > 0)
		free(str);
	return (-1);
}
