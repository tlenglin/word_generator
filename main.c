/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:50:28 by tlenglin          #+#    #+#             */
/*   Updated: 2017/05/01 17:13:09 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word_generator.h"

int	display_proba(int proba[27][27])
{
	int	i;
	int	j;

	i = 0;
	ft_printf("    0   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o   p   q   r   s   t   u   v   w   x   y   z\n");
	while (i < 27)
	{
		ft_printf("%c ", i == 0 ? '0' : 'a' + i - 1);
		j = 0;
		while (j < 27)
		{
			ft_printf("%3i ", proba[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return (0);
}

int	proba_initialization(int proba[27][27])
{
	int		i;
	int		j;

	i = 0;
	while (i < 27)
	{
		j = 0;
		while (j < 27)
		{
			proba[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		proba[27][27];
	int		fd;

	if (argc != 2)
	{
		ft_printf("arg error\n");
		return (0);
	}
	proba_initialization(proba);
	if ((fd = file_cleaner(argv[1])) == -1)
		return (0);
	install(proba, fd);
	display_proba(proba);
	// remove("file_cleaned");
	return (0);
}
