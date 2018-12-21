/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 13:54:40 by jleblond          #+#    #+#             */
/*   Updated: 2018/12/21 13:54:43 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int 	main(int argc, char **argv)
{
	int		ret;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit file");
		return (0);
	}
	ret = verif(argv[1]); //all error situaion will return -1
	if (ret == -1)
	{
		return (0);
	}

	return (0);
}
