/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:31:09 by dkaplan           #+#    #+#             */
/*   Updated: 2018/06/05 17:04:55 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static int    ft_read_buffer(int const fd, char **line)
{
    char    *buff;
    int        ret;
    //char    *tmp;

    if (!(buff = (char *)malloc(sizeof(*buff)* (BUFF_SIZE + 1))))
        return (-1);
    ret = read(fd, buff, BUFF_SIZE);
    if (ret > 0)
    {
        buff[ret] = '\0';
        *line = ft_strjoin(*line, buff);
        free(*line);
        //*line = tmp;
		free(buff);
    }
    return (ret);
}

int            get_next_line(int const fd, char **line)
{
    static char    *str;
    char        *find_newl;
    int            ret;

    if ((!str && (!(str = (char *)malloc(sizeof(char))))) 
			|| fd < 0 || BUFF_SIZE < 0)
        return (-1);
    find_newl = ft_strchr(str, '\n');
    while (find_newl == NULL)
    {
        ret = ft_read_buffer(fd, &str);
        if (ret == 0)
        {
            if (ft_strlen(str) == 0)
                return (0);
           // str = ft_strjoin(str, "X");
        }
        if (ret < 0)
            return (-1);
        else
            find_newl = ft_strchr(str, '\n');
    }
    *line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(find_newl));
    str = ft_strdup(find_newl + 1);
    return (1);
}
