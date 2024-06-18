/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:36:03 by rmakende          #+#    #+#             */
/*   Updated: 2024/06/18 20:58:45 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;

	ptr = ft_strchr(storage, '\n');
	if (!(ptr))
		return (ft_free(&storage));
	ptr++;
	if (!*ptr)
		return (ft_free(&storage));
	new_storage = ft_strdup(ptr);
	ft_free(&storage);
	return (new_storage);
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_buffer(int fd, char *storage)
{
	int		rid;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	rid = read(fd, buffer, BUFFER_SIZE);
	while (rid > 0)
	{
		buffer[rid] = '\0';
		if (!storage)
			storage = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(storage, buffer);
			free(storage);
			storage = tmp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (rid == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = read_buffer(fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (ft_free(&storage));
	storage = clean_storage(storage);
	return (line);
}
/*

int main(int argc, char **argv)
{
	if (argc > 0)
	{
		char *line;
		int fd;

		fd = open(argv[1], O_RDONLY);
		while ((line = get_next_line(fd)))
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
	}
	return (0);
}
*/
