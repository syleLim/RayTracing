#include "parser.h"

int     ft_strslen(char **strs)
{
    int i;

    i = -1;
    while (*(strs + (++i)))
        ;
    return (i);
}