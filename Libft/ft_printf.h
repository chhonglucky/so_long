/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhhon <chanhhon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:04:09 by chanhhon          #+#    #+#             */
/*   Updated: 2023/12/27 16:47:56 by chanhhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../Libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_format(va_list args, const char *formats);
int		ft_parsing(va_list args, const char format);
int		ft_print_char(int i);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_nbr(int nbr);
int		ft_print_unsigned(unsigned int u);
int		ft_print_hex(unsigned int u, const char format);
int		ft_print_percent(void);
void	ft_putnbr_base(unsigned long long nbr, char *base, int *flag);

#endif