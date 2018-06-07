/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 16:31:09 by dkaplan           #+#    #+#             */
/*   Updated: 2018/06/07 15:32:55 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

static int			ft_read_buffer(int const fd, char **line)
{
	char	*buff;
	int		ret;
	char	*tmp;

	if (!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = 0;
		if (!(tmp = ft_strjoin(*line, buff))) 									// MALLOC line+buff in fresh string
			return (-1);
		free(*line);
		*line = tmp;
		free(buff);
	}
	if (ret == 0)
		free(buff);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		*str;														//either is \0 or the left over of what we had before excluding the \n
	char			*find_newl;													// will be set as everything str from and including the \n later on   
	int				ret;														//will be set as how many bytes read. -1 == fail 0 == finished reading
																				// norminette made me waste this line
	if ((!str && (!(str = (char*)malloc(sizeof(char) * BUFF_SIZE + 1))))		//if (str is null ((( if true then it will maloc and see if malloc fails, else it wont even look at the second condition))) 
			|| fd < 0 || BUFF_SIZE < 0)											// / fd == -1 / BUFF = -1 or less )
		return (-1);															//then theres an error
	find_newl = ft_strchr(str, '\n'); 											//find_newl = everything after \n incl \n
	while (!find_newl)															//while (newline is nothing)
	{																			// {
		ret = ft_read_buffer(fd, &str); 										//RETURN amount read in buffer and set str as what is read
		if (ret == 0)															// if (ret == 0) / i.e no bytes were read, end of file
		{																		// {
			if (!ft_strlen(str))												// if str == no chars
				return (0);														// return 0, because we're done reading
			ft_strcat(str, "\n");												// else str = str+\n so it will copy nothing on line 64
		}																		// } 
		if (ret < 0)															// if (ret is -1).. i.e read failed
			return (-1);														// then theres an error
		else																	//else 
			find_newl = ft_strchr(str, '\n');									//find_newl  = everything in str after \n incl \n
	}																			// }
	if (!(*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(find_newl))))	//if (MALLOCED) line = str from str[i] up till str[length of str - length of newl] == (NULL)
		return (-1);															//then we have ourselves another error
	ft_strcpy(str, find_newl + 1);												// copy newl+1 to str.. i.e. everything passed the \n will get copied over to str. eg newl = "\nfdgfgfg" then str = "nfgdfgdfg"
	return (1);																	//success
}
