/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_generator.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 12:54:41 by tlenglin          #+#    #+#             */
/*   Updated: 2017/05/01 17:10:34 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_GENERATOR_H
# define WORD_GENERATOR_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

int	install(int	proba[27][27], int fd);
int	file_cleaner(char *file_name);

#endif
