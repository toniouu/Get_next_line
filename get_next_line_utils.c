/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atovoman <atovoman@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:12:12 by atovoman          #+#    #+#             */
/*   Updated: 2024/04/11 18:24:08 by atovoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	checking_newline(char *readed)
{
	int	i;

	i = 0;
	while (readed[i] != '\0')
	{
		if (readed[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *readed)
{
	int	i;

	i = 0;
	if (!readed)
		return (0);
	while (readed[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	size_t	i;

	i = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
