/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoudi-b <mdoudi-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:22:48 by mdoudi-b          #+#    #+#             */
/*   Updated: 2024/02/18 17:12:11 by mdoudi-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char	*strjoin, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	free(s1);
	return (strjoin);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = ft_calloc(ft_strlen(s2) + 2, sizeof(char));
		if (!s1)
			return (NULL);
	}
	strjoin = ft_calloc((ft_strlen(s1)
				+ ft_strlen(s2) + 2), sizeof(char));
	if (strjoin == NULL)
		return (free(s1), NULL);
	strjoin = ft_strjoin2(strjoin, s1, s2);
	return (strjoin);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL || s[0] == '\0')
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*array;

	i = 0;
	array = (char *)malloc(count * size);
	if (!array)
		return (0);
	while (i < count * size)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
