/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:48:46 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/15 11:25:27 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_putchar(char a);
int	ft_putnbr(int a, int *s);
int	ft_putstr(char *s);
int	ft_checker(char a, va_list *args);
int	ft_printf(const char *s, ...);
int	ft_upperx(unsigned int a, int *s);
int	ft_lowerx(unsigned int a, int *s);
int	ft_pointer(unsigned long long a, int *s);
int	ft_unsigned(unsigned int a, int *s);

#endif