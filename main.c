/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:19:09 by dkaplan           #+#    #+#             */
/*   Updated: 2018/06/07 15:25:11 by dkaplan          ###   ########.fr       */
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
	while ((get_next_line(fd, &line) == 1 || get_next_line(fd, &line) == 0) && i < 20)
	{
    	printf("%d", i);
		ft_putendl(line);
		if (i <= 11)
		free(line);
		i++;
	}
	if (get_next_line(fd, &line) == 0)
	{
		ft_putendl(line);
		i++;
	}
	return(0);
}	
