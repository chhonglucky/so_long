/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csfunc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongchanhyeong <hongchanhyeong@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:56:42 by chanhhon          #+#    #+#             */
/*   Updated: 2024/05/10 14:47:23 by hongchanhye      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSFUNC_H
# define CSFUNC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "ft_printf/includes/ft_printf.h"

void	unix_error(char *msg);
pid_t	shell_fork(void);
void	shell_execve(const char *filename, char *argv[], char *const envp[]);
pid_t	shell_waitpid(pid_t pid, int *iptr, int options);
int		shell_open(const char *pathname, int flags, mode_t mode);
void	shell_close(int fd);
int		shell_dup2(int fd1, int fd2);
void	shell_pipe(int fd[2]);

#endif
