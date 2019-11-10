/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquamar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 01:32:53 by aquamar           #+#    #+#             */
/*   Updated: 2019/11/10 04:02:21 by aquamar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getlines(int fd, char *str)
{
	char	*temp;
	int		ret;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = 0;
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(str, '\n') == NULL)
	{
		if ((ret = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free(buffer);
			return (0);
		}
		buffer[ret] = '\0';
		temp = str;
		str = ft_strjoin(str, buffer);
		free(temp);
		if (ret == 0 || str[0] == '\0')
			break ;
	}
	free(buffer);
	return (str);
}

int		fonction_if(int fd, char **line, char c)
{
	if (fd < 0 || !line || read(fd, &c, 0))
		return (-1);
	return (1);
}

void	ft_strdel(char **s)
{
	free(*s);
	*s = NULL;
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	size_t			len;
	char			*temp;
	char			c;

	if (fonction_if(fd, line, c) == -1)
		return (-1);
	if ((str = ft_getlines(fd, str)) == NULL)
		return (0);
	if (!(ft_strchr(str, '\n')))
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		ft_strdel(&str);
		return (0);
	}
	else
	{
		len = ft_strchr(str, '\n') - str;
		temp = str;
		*line = ft_substr(str, 0, len);
		str = ft_strdup(str + len + 1);
		free(temp);
		return (1);
	}
}
