/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:10:40 by jleblond          #+#    #+#             */
/*   Updated: 2018/12/21 16:10:44 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"




int		verif(char *argv)
{
	int		fd;
	char	*line;
	int		x;
	int		ret;

	ret = 1;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("open()error");
		return (-1);
	}
	x = 1;
	while (1)
	{
		printf("x:%d\n", x);
		ret = get_next_line(fd, &line);
		if (ret != 1)
			break;
		if (x % 5 == 0)
		{
			if (line[0] != '\0')
				printf("line[0] != '\0'");
		}
		if (x % 5 != 0)
		{
			//if (line[4] != '\n')
			printf("%c\n", line[4]);
		}
		x++;
	}

	close(fd);
	return (1);
}

