/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:55:43 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/19 16:36:18 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	str = ft_calloc(sizeof(char), i + 1);
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

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	size_t		sizemax;
	static char	*current;
	int 		index;
	
	if (fd < 0  || fd > FD_MAX || BUFFER_SIZE < 1 || !*line)
		return (-1);
	*line = malloc(1);
	if (!*line)
		return (-1);
	sizemax = 1;
	while (sizemax > 0)
	{
		sizemax = read(fd, buffer, BUFFER_SIZE);
		buffer[sizemax] = '\0';
		if (ft_strchr(buffer, '\n'))
			line = ft_strjoin(*line, ft_strchr(buffer, '\n'));
	}
}
