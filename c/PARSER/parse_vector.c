#include "parser.h"

void    parse_vector(vec v, char *str, double div)
{
    char **strs;

    if (!(strs = ft_split(str, ',')))
        exit(1);
    v[X] = ft_atof(strs[X]) / div;
    v[Y] = ft_atof(strs[Y]) / div;
    v[Z] = ft_atof(strs[Z]) / div;
    ft_free_strs(strs);
}
