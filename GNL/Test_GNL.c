/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_GNL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:11:04 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/20 13:59:32 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../Libft/libft.h"
#include "get_next_line.h"

int main()
{
	char	*line;
	int		fd = 0;
	int		gnl = 1;
	int 	i;

	fd = open("/User/lmaujean/Projet42/GNL/text.txt", O_RDONLY, 1);
	i = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		printf("line %d: {%s}(%d)\n", i, line, gnl);
		free(line);
		i++;
	}
}
