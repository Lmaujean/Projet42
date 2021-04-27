/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_GNL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:11:04 by lmaujean          #+#    #+#             */
/*   Updated: 2021/04/26 02:32:09 by louismauj        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../Libft/libft.h"
#include "./get_next_line.h"

int main()
{
//	char	*line;
	int		fd = 0;
//	int		gnl = 1;
//	int 	i;
	char	*str;

	fd = open("/Users/louismaujean/42/GNL/text.txt", O_RDONLY);
	printf("%d\n", get_next_line(fd, &str));
	printf("%s\n", str);
	printf("%d\n", get_next_line(fd, &str));
	printf("%s\n", str);

	return 0;
}
