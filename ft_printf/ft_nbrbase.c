/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:59:19 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/15 11:19:23 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_putnbr(int a, int *s)
{
	if (a == -2147483648)
	{
		*s += ft_putchar('-');
		*s += ft_putchar('2');
		a = 147483648;
	}
	if (a < 0)
	{
		*s += ft_putchar('-');
		a *= -1;
	}
	if (a < 10)
		*s += ft_putchar(a + 48);
	if (a > 9)
	{
		ft_putnbr(a / 10, s);
		ft_putnbr(a % 10, s);
	}
	return (*s);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
