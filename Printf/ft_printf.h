#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "Libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct s_list
{
    int     j;
    char    *tab;
    int     index;
    unsigned int u;
    unsigned long x;
    unsigned long long p; 

}               t_list;

int ft_printf(const char *str, ...);


#endif