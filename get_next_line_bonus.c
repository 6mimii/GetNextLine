/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:21:17 by mdoudi-b          #+#    #+#             */
/*   Updated: 2024/02/18 17:06:42 by mdoudi-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_rest_file(char *save)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\0')
		return (free(save), NULL);
	aux = ft_calloc((ft_strlen(save) - i + 1), sizeof(char));
	if (!aux)
		return (free(save), NULL);
	i++;
	j = 0;
	while (save[i])
	{
		aux[j] = save[i];
		i++;
		j++;
	}
	aux[j] = '\0';
	return (free(save), aux);
}

char	*ft_read_file(int fd, char *save)
{
	int		bufferread;
	char	*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (free(save), NULL);
	bufferread = 1;
	while (!ft_strchr(buffer, '\n') && bufferread > 0)
	{
		bufferread = read(fd, buffer, BUFFER_SIZE);
		if (bufferread == -1)
		{
			free(buffer);
			free(save);
			return (0);
		}
		buffer[bufferread] = '\0';
		if (buffer[0] != '\0')
			save = ft_strjoin(save, buffer);
	}
	return (free(buffer), save);
}

char	*ft_read_line(char *save)
{
	char	*line;
	int		i;
	int		j;

	if (save[0] == '\0')
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (i > j)
	{
		line[j] = save[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save[1666];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save[fd] = ft_read_file(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_read_line(save[fd]);
	save[fd] = ft_rest_file(save[fd]);
	return (line);
}
