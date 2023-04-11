/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:05:39 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/16 12:21:34 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(char a, va_list *args)
{
	int	i;

	i = 0;
	if (a == 'c')
		i += ft_putchar(va_arg(*args, int));
	if (a == 'd' || a == 'i')
		ft_putnbr(va_arg(*args, int), &i);
	if (a == 's')
		i += ft_putstr(va_arg(*args, char *));
	if (a == '%')
		i += write(1, "%", 1);
	if (a == 'p')
	{
		i += write(1, "0x", 2);
		ft_pointer(va_arg(*args, unsigned long long), &i);
	}
	if (a == 'u')
		ft_unsigned(va_arg(*args, unsigned int), &i);
	if (a == 'x')
		ft_lowerx(va_arg(*args, unsigned int), &i);
	if (a == 'X')
		ft_upperx(va_arg(*args, unsigned int), &i);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_checker(s[i], &args);
		}
		else
		{
			len += ft_putchar(s[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int main()
{
	int a;
	int *b;

	a = 5123;
	b = &a;
	ft_printf("c = %c\n", 'E');
	ft_printf("%d\n", *b);
	ft_printf("%i\n", *b);
	ft_printf("%u\n", *b);
	ft_printf("%x\n", 123123123);
	ft_printf("%X\n", 123123123);
	ft_printf("%p\n", *b);
	ft_printf("%s\n", "mertflix");
}*/
