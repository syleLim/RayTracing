/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seolim <seolim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:29:13 by seolim            #+#    #+#             */
/*   Updated: 2020/07/15 16:13:35 by seolim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*file_cat(char *file, char *new, int new_len)
{
	char	*new_file;
	int		file_len;
	int		i;

	file_len = ft_strlen(file);
	if (!(new_file = malloc(sizeof(char) *
			(file_len + new_len + 1))))
		return (NULL);
	i = -1;
	while (++i < file_len)
		new_file[i] = file[i];
	i = -1;
	while (++i < new_len)
		new_file[file_len + i] = new[i];
	new_file[file_len + i] = 0;
	free(file);
	return (new_file);
}

char	*read_file(char *file, int fd, int *code)
{
	char	buf[BUFFER_SIZE + 1];

	if (!file)
	{
		if (!(file = (char *)malloc(sizeof(char))))
			return (NULL);
		*file = 0;
	}
	if ((*code = read(fd, buf, BUFFER_SIZE)) > 0)
		file = file_cat(file, buf, *code);
	return (file);
}

char	*fill_line(char **line, char *file, int len, int *code)
{
	char	*new_file;
	int		file_len;
	int		i;

	file_len = ft_strlen(file);
	i = -1;
	*line = ft_strdup(file, &i, len);
	if (file[i] == '\n')
		len++;
	if (!(new_file = malloc(sizeof(char) *
			(file_len - len + 1))))
	{
		*code = -1;
		return (NULL);
	}
	i = -1;
	while (++i < file_len - len)
		new_file[i] = file[len + i];
	new_file[i] = 0;
	free(file);
	return (new_file);
}

void	fill_last(char **line, char **file)
{
	int file_len;
	int i;

	file_len = ft_strlen(*file);
	i = -1;
	*line = ft_strdup(*file, &i, file_len);
	free(*file);
	*file = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char		*files[MAX_FD];
	int				code;
	int				len;

	code = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((len = find_n(files[fd])) < 0)
	{
		files[fd] = read_file(files[fd], fd, &code);
		if (code == -1 || files[fd] == NULL)
			return (free_file(files[fd]));
		if (code == 0)
			break ;
	}
	if (len == -1 && code == 0 && files[fd])
		fill_last(line, &files[fd]);
	else
		files[fd] = fill_line(line, files[fd], len, &code);
	if (code == -1)
		return (free_file(files[fd]));
	return (code < 1 ? code : 1);
}
