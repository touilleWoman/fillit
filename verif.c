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
	char	*block[500];
	int		x;
	int		ret;

	ret = 1;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("open()error");
		return (-1);
	}
	x = 0;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		block[x] = ft_strdup(line);
		printf("block[%d]%s\n", x, block[x]);
		x++;
	}

	close(fd);
	return (1);
}

