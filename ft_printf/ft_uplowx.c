/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uplowx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:48:33 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/15 11:23:23 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upperx(unsigned int a, int *s)
{
	if (a < 16)
	{
		if (a < 10)
			*s += ft_putchar(a + 48);
		else
			*s += ft_putchar(a + 55);
	}
	else
	{
		ft_upperx(a / 16, s);
		ft_upperx(a % 16, s);
	}
	return (*s);
}

int	ft_lowerx(unsigned int a, int *s)
{
	if (a < 16)
	{
		if (a < 10)
			*s += ft_putchar(a + 48);
		else
			*s += ft_putchar(a + 87);
	}
	else
	{
		ft_lowerx(a / 16, s);
		ft_lowerx(a % 16, s);
	}
	return (*s);
}

int	ft_pointer(unsigned long long a, int *s)
{
	if (a < 16)
	{
		if (a < 10)
			*s += ft_putchar(a + 48);
		else
			*s += ft_putchar(a + 87);
	}
	else
	{
		ft_pointer(a / 16, s);
		ft_pointer(a % 16, s);
	}
	return (*s);
}

int	ft_unsigned(unsigned int a, int *s)
{
	if (a <= 9 && a >= 0)
		*s += ft_putchar(a + 48);
	else
	{
		ft_unsigned(a / 10, s);
		ft_unsigned(a % 10, s);
	}
	return (*s);
}
