#include "parser.h"

int ft_is_num(char c)
{
    if ('0' <= c && c <= '9')
        return (1);
    return (0);
}