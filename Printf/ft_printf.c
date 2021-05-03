#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list args;
    int i;
    t_list struc;

    i = 0;
    struc.index = 0;
    va_start(args);
    while (str[i] != 0)
    {
        if (str[i] != '%')
        {
            ft_putchar_fd(str[i], 1);
            struc.index++;
        }
        else
        {
            i++;
            if (str[i] == 'c')
            {
                struc.j = va_arg(args, int);
                ft_putchar_fd(struc.j, 1);
                struc.index++;
            }
            else if (str[i] == 's')
            {
                struc.tab = va_arg(args, char *);
                ft_putstr_fd(struc.tab, 1);
                struc.index += ft_strlen(struc.tab);
            }
            else if (str[i] == '%')
            {
                struc.j = va_arg(args, int);
                ft_putchar_fd(struc.j, 1);
                struc.index++;
            }
            else if (str[i] == 'd' || str[i] == 'i')
            {
                struc.j = va_arg(args, int);
                ft_putnbr_fd(struc.j, 1);
            }
            else if (str[i] == 'u')
            {
                struc.u = va_arg(args, unsigned int);
                // faire un putnbr unsigned
            }
            else if (str[i] == 'x' || str[i] == 'X')
            {
                struct.x = va_arg(args, unsigned long);
                // faire un itoa_base
            }
            else if (str[i] == 'p')
            {
                struc.p = va_arg(args, unsigned long long);
                // faire un itoa_base pas trop comme celui de haut dessus
            }
        }
        i++; 
    }
    va_end(args);
    return (index);
}

