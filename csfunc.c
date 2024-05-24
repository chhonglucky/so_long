/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csfunc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:04:01 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/24 16:05:40 by chanhhon         ###   ########.fr       */
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

int	shell_read(int fd, void *buf, size_t count)
{
	ssize_t	rc;

	rc = read(fd, buf, count);
	if (rc < 0)
		unix_error("Read error");
	return (rc);
}

int	shell_write(int fd, const void *buf, size_t count)
{
	ssize_t	rc;

	rc = write(fd, buf, count);
	if (rc < 0)
		unix_error("Write error");
	return (rc);
}

void	shell_close(int fd)
{
	int	rc;

	rc = close(fd);
	if (rc < 0)
		unix_error("Close error");
}

void	*shell_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (p == NULL)
		unix_error("Malloc error");
	return (p);
}
