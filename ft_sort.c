/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:11:19 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 00:10:36 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fivesort(t_list *main)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		while (main->sort_a[2] <= main->stacka[0])
			ra(main);
		if (main->sort_a[2] > main->stacka[0])
			pb(main);
		i++;
	}
	threesort(main);
	if (main->stackb[0] < main->stackb[1])
		sb(main);
	i = 0;
	while (i < 2)
	{
		pa(main);
		i++;
	}
}

void	threesort(t_list *main)
{
	if ((main->stacka[2] > main->stacka[0]) \
	&& (main->stacka[1] < main->stacka[0]))
		sa(main);
	else if ((main->stacka[0] > main->stacka[1]) \
	&& (main->stacka[0] > main->stacka[2]) \
	&& (main->stacka[1] < main->stacka[2]))
		ra(main);
	else if ((main->stacka[1] > main->stacka[0]) \
	&& (main->stacka[1] > main->stacka[2]) \
	&& (main->stacka[2] < main->stacka[0]))
		rra(main);
	else if ((main->stacka[0] > main->stacka[1]) \
	&& (main->stacka[0] > main->stacka[2]) \
	&& (main->stacka[2] < main->stacka[1]))
	{
		sa(main);
		rra(main);
	}
	else if ((main->stacka[1] > main->stacka[0]) \
	&& (main->stacka[1] > main->stacka[2]) \
	&& (main->stacka[0] < main->stacka[2]))
	{
		rra(main);
		sa(main);
	}
}

int	find_index(t_list *main, int a)
{
	int	i;

	i = 0;
	while (i < main->fake_alen)
	{
		if (main->sort_a[i] == a)
			break ;
		i++;
	}
	return (i);
}

int	max_bit(t_list *main)
{
	int	i;
	int	j;

	j = main->alen - 1;
	i = 0;
	while (j)
	{
		j >>= 1;
		i++;
	}
	return (i);
}

void	radix_sort(t_list *main)
{
	int	i;
	int	j;
	int	x;
	int	bit;

	bit = max_bit(main);
	i = 0;
	while (i < bit)
	{
		j = 0;
		while (j < main->fake_alen)
		{
			x = find_index(main, main->stacka[0]);
			if ((x >> i) & 1)
				ra(main);
			else
				pb(main);
			j++;
		}
		while (main->blen)
			pa(main);
		i++;
	}
}
