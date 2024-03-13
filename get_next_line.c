/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:36:20 by mdoudi-b          #+#    #+#             */
/*   Updated: 2024/02/20 17:21:14 by mdoudi-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_file(fd, save);
	if (!save)
		return (NULL);
	line = ft_read_line(save);
	save = ft_rest_file(save);
	return (line);
}

/*int	main(void)
{
	int	fd;

	fd = open("txt.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}*/
