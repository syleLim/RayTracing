#include "parser.h"

bool		ft_free_strs(char **strs)
{
	int i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
	return (FALSE);
}