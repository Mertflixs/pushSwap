/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:47:07 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/19 20:38:15 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_list *main)
{
	int		i;
	long	num;
	int		neg;

	num = 0;
	neg = 1;
	i = 0;
	if (str[i] == '-')
		neg *= -1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i] <= 57 && str[i] >= 48)
	{
		num = num * 10 + (str[i] - 48);
		if (num * neg > 2147483647)
			ft_exit(main, 2);
		else if (num * neg < -2147483648)
			ft_exit(main, 2);
		i++;
	}
	if (str[i] != '\0')
		ft_exit(main, 2);
	return ((int)num * neg);
}
