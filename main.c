/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaplan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:19:09 by dkaplan           #+#    #+#             */
/*   Updated: 2018/06/04 16:59:41 by dkaplan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	(void)ac;
	int fd;
	char *line = "a";

	fd = open(av[1], O_RDONLY);
	get_next_line(fd, &line);
	free(line);
	get_next_line(fd, &line);
}	
