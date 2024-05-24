/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csfunc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:56:42 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:44:08 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSFUNC_H
# define CSFUNC_H

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "../Libft/ft_printf.h"

void	unix_error(char *msg);
int		shell_open(const char *pathname, int flags, mode_t mode);
void	*shell_malloc(size_t size);

#endif
