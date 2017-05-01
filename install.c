/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   install.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:50:12 by tlenglin          #+#    #+#             */
/*   Updated: 2017/05/01 17:15:19 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word_generator.h"

int	file_cleaner(char *file_name)
{
	int		i;
	int		fd;
	int		fd2;
	char	*line;
	int		count;
	int		error;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_printf("open failure -> %s\n", file_name);
		return (-1);
	}
	if ((fd2 = open("file_cleaned", O_RDWR | O_CREAT, S_IRWXO)) == -1)
	{
		ft_printf("open failure -> file_cleaned\n");
		return (-1);
	}
	count = 0;
	error = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		while ((unsigned char)line[i])
		{
			if (((unsigned char)line[i] <= 229 && (unsigned char)line[i] >= 224) || ((unsigned char)line[i] <= 197 && (unsigned char)line[i] >= 192)) //a
				line[i] = 'a';
			else if (((unsigned char)line[i] <= 235 && (unsigned char)line[i] >= 232) || ((unsigned char)line[i] <= 203 && (unsigned char)line[i] >= 200)) //e
				line[i] = 'e';
			else if (((unsigned char)line[i] <= 239 && (unsigned char)line[i] >= 236) || ((unsigned char)line[i] <= 207 && (unsigned char)line[i] >= 204)) //i
				line[i] = 'i';
			else if (((unsigned char)line[i] <= 246 && (unsigned char)line[i] >= 243) || ((unsigned char)line[i] <= 214 && (unsigned char)line[i] >= 211)) //o
				line[i] = 'o';
			else if (((unsigned char)line[i] <= 252 && (unsigned char)line[i] >= 249) || ((unsigned char)line[i] <= 220 && (unsigned char)line[i] >= 217)) //u
				line[i] = 'u';
			else if (line[i] <= 'Z' && line[i] >= 'A')
				line[i] = line[i] - 'A' + 'a';
			if (!(line[i] <= 'z' && line[i] >= 'a'))
			{
				ft_printf("invalid char >>%c<< line %i\n", line[i], count);
				error = 1;
			}
			i++;
		}
		count++;
		ft_printf("%s\n", line);
		ft_putstr_fd(line, fd2);
	}
	if (close(fd) == -1)
	{
		ft_printf("close failure\n");
		return (-1);
	}
	if (error == 1)
	{
		remove("file_cleaned");
		return (-1);
	}
	return (fd2);
}

int	install(int	proba[27][27], int fd)
{
	char	*line;
	int		i;

	while (get_next_line(fd, &line))
	{
		i = 0;
		proba[0][line[0] - 'a' + 1]++;
		while (line[i])
		{
			proba[line[i] - 'a' + 1][(line[i + 1]) != '\0' ? line[i + 1] - 'a' + 1 : 0]++;
			i++;
		}
	}
	if (close(fd) == -1)
	{
		ft_printf("close failure\n");
		return (0);
	}
	return (1);
}
