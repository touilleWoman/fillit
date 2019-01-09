/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamart <tlamart@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:05:55 by tlamart           #+#    #+#             */
/*   Updated: 2018/12/16 15:35:55 by thibault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include "fillit.h"

static int		get_file(const int fd, char **file)
{
	if (!(*file = ft_strnew(BUFF_SIZE)))
		exit(EXIT_FAILURE);
	return (read(fd, *file, BUFF_SIZE));
}


static void	get_tetri(char *file, t_list **lst)
{
	char	letter;
	t_list	*list;
	int		i;
	char	*str;

	letter = 'A';
	list = *lst;
	while (list)
	{
		i = 0;
		str = (char*)(list->content);
		while (str[i])
		{
			if (*file == '#')
				str[i] = letter;
			file++;
			i++;
		}
		list = list->next;
		letter++;
	}
}

static char	*create_square(int size)
{
	char	*square;
	int		i;
	int		len;
	int		total_size;

	square = ft_strnew(size * (size + 1));
	i = 0;
	len = 0;
	total_size = size * (size + 1);
	while (i < total_size)
	{
		if (len == size)
		{
			square[i] = '\n';
			len = 0;	
		}
		else
		{
			len++;
			square[i] = '.';
		}
		i++;
	}
	return (square);
}
/*
static int	try_tetri(char *square, t_list tetri)
{
	
}

static void	fillit(int size, t_list list)
{
	char	*answer;

	answer = create_square(size);

}
*/

static void	put_one_tetri(char **square, t_list *tetri)
{
	char	*str;
	char	*ret;

	str = (char*)(tetri->content);
	ret = *square;
	while (*str)
	{
		if ('A' <= *str && *str <= 'Z')
		{
			*ret = *str;
			ret++;
		}
		if (*str == '\n')
			ret = ft_strchr(ret, '\n');
		str++;
//		ret++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	char	*file;
	int		ret;
	t_list	*tetri;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	ret = get_file(fd, &file);
	if ((ret + 1) % 21 != 0)
	{
		ft_putendl("INVALID FILE");
		return (0);
	}
	tetri = ft_lstset("....\n....\n....\n....\n\n", 21, (ret + 1) / 21);
	get_tetri(file, &tetri);
//	ft_putlst(tetri);
	ft_strdel(&file);
	close(fd);
	file = create_square(10);
	put_one_tetri(&file, tetri);
	ft_putendl(file);
	ft_strdel(&file);
	ft_lstdel(&tetri, &ft_lstdel_cnt);
	return (0);
}
