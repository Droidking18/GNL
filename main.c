/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:19:09 by dkaplan           #+#    #+#             */
/*   Updated: 2018/06/06 14:55:26 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	(void)ac;
	int fd;
	char *line;
	int i = 0;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
    	printf("%d", i);
		ft_putendl(line);
		free(line);
		i++;
	}
	return(0);
}	
