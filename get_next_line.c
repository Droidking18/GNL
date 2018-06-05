/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:21:15 by dkaplan           #+#    #+#             */
/*   Updated: 2018/06/05 12:16:15 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		returnplace(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(int const fd, char **line)
{
    static char *data;
	int i;
	char *temp;

	if ((!(data = ft_strnew(BUFF_SIZE))) || (!(temp = ft_strnew(BUFF_SIZE))))
		return (-1);
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
	read(fd, data, BUFF_SIZE);
	while (data[i] != '\n' && data[i] != '\0')
	{
		if (!data)
			return (0);
		if (data[i] == '\n' || data[i] == '\0')
		{
			ft_strcat(data, temp);
			if (!(*line = ft_strdup(data)))
			{
				free(data);
				return (-1);
			}
			free(data);
			return (1);
		}
		if (i == ft_strlen(data))
		{
			if (!(*line = ft_strdup(data)))
				return (-1);
			read(fd, data, BUFF_SIZE);
			ft_strcat(data, temp);
		}
		i++;
	}
	return(1);
	free(data);
}
