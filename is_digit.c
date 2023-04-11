/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:30:35 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 13:02:03 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit_2(char *arr, t_list *main)
{
	int	i;

	ft_atoi(arr, main);
	i = 0;
	while (arr[i])
	{
		if (arr[i] > '9' && arr[i] < '0')
		{
			if (arr[i] == '-' || arr[i] == '+')
			{
				i++;
				if (arr[i] == '-' || arr[i] == '+')
					return (0);
			}
		}
		else
			i++;
	}
	return (1);
}

int	is_digit(char **arr, t_list *main)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (is_digit_2(arr[i], main) == 0)
			ft_exit(main, 2);
		i++;
	}
	return (1);
}
