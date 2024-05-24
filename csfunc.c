/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:04:01 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 19:20:00 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "csfunc.h"

void	unix_error(char *msg)
{
	extern int	errno;

	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errno);
}

int	shell_open(const char *pathname, int flags, mode_t mode)
{
	int	rc;

	rc = open(pathname, flags, mode);
	if (rc < 0)
		unix_error("Open error");
	return (rc);
}

void	*shell_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		unix_error("Malloc error");
	return (p);
}
