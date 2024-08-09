/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 08:36:43 by atovoman          #+#    #+#             */
/*   Updated: 2024/04/15 08:30:43 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*add_to_readed(char *readed, char *buf)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = ft_strlen(readed);
	j = ft_strlen(buf);
	dest = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (0);
	i = 0;
	while (readed[i] != '\0')
	{
		dest[i] = readed[i];
		i++;
	}
	j = 0;
	while (buf[j] != '\0')
		dest[i++] = buf[j++];
	dest[i] = '\0';
	free(readed);
	return (dest);
}

static char	*read_this_file(char *readed, int fd)
{
	char	*buf;
	int		len_readed;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	len_readed = 1;
	if (!readed)
		readed = ft_strdup("");
	while (checking_newline(readed) == 0 && len_readed != 0)
	{
		len_readed = read(fd, buf, BUFFER_SIZE);
		if (len_readed == -1 || (len_readed == 0 && readed[0] == '\0'))
		{
			free(readed);
			free(buf);
			return (0);
		}
		buf[len_readed] = '\0';
		readed = add_to_readed(readed, buf);
	}
	free(buf);
	return (readed);
}

static char	*extract_line(char *readed)
{
	char	*line;
	int		i;

	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (readed[i])
	{
		if (readed[i] == '\n')
		{
			line[i] = readed[i];
			i++;
			break ;
		}
		line[i] = readed[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*clean_readed(char *readed)
{
	char	*new_readed;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (checking_newline(readed) == 1)
	{
		while (readed[i] != '\n')
		{
			i++;
		}
		new_readed = (char *)malloc(sizeof(char) * (ft_strlen(readed) - i));
		if (new_readed == NULL)
			return (0);
		i += 1;
		while (readed[i])
			new_readed[j++] = readed[i++];
		new_readed[j] = '\0';
		free(readed);
		return (new_readed);
	}
	free(readed);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	readed = read_this_file(readed, fd);
	if (!readed || readed[0] == '\0')
		return (0);
	line = extract_line(readed);
	if (!line)
		return (0);
	readed = clean_readed(readed);
	return (line);
}
