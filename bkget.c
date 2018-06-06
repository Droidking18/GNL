/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:21:15 by dkaplan           #+#    #+#             */
/*   Updated: 2018/06/05 16:30:27 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char		*ft_realloncpy(char *str, char *str2, int i, int j)
{
	char	*newstr;

	if(!(newstr = ft_strnew(i)))
		return (NULL);
	if (str)
	{
		ft_strncat(newstr, str, j);
		free(str);
		ft_strncat(newstr, str2, j);
	}
	return (newstr);
}

int		get_next_line(int const fd, char **line)
{
    static char data[BUFF_SIZE + 1];
	static int	i;
	int			size;
    char		*temp;

	//if ((!(data = ft_strnew(BUFF_SIZE))) || (!(temp = ft_strnew(BUFF_SIZE))))
	//	return (-1);
	i = 0;
	if (fd < 0 || !line || read(fd, data, 0) < 0)
		return (-1);
	/*read(fd, data, BUFF_SIZE);
	data[BUFF_SIZE] = 0;
	if (!(*line = ft_strdup(data)))
		return (-1);
	if (!(ft_strchr(data, '\n')))
		read(fd, temp, BUFF_SIZE);
	else if (ft_strcmp(ft_strchr(data, '\n'), "\n") == 0)
	{
		ft_strcpy(*line, data);
		return (1);
	}
	while (!(ft_strchr(temp, '\n')))
		read(fd, temp, BUFF_SIZE);
	printf("line%s\n", line[0]);
	//printf("temp%s\n", temp);
	return (i);*/
	size = read(fd, data, BUFF_SIZE);
	data[size] = 0;
	while (i <= BUFF_SIZE)
	{
		if (i == BUFF_SIZE)
			i = 0;
		if (data[0] == 0)
			return (0);
		if (data[i] == '\n' || data[i] == '\0')
		{
			ft_realloncpy(*line, data, ft_strlen(data) + ft_strlen(*line), i);
			if (!(*line = ft_strndup(data, i)))
				return (-1);
			return (1);
		}
		if (i == ft_strlen(data))
		{
			if (!(temp = ft_strdup(data)))
				return (-1);
			read(fd, data, BUFF_SIZE);
			ft_realloncpy(*line, data, ft_strlen(data) + ft_strlen(*line), i);
		}
		i++;
	}
	return(0);
}
