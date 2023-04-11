/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:36:13 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 13:03:48 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*swipe_down(int *arr, int a)
{
	int	i;
	int	temp;
	int	*stack;

	i = 1;
	stack = malloc(sizeof(int) * a + 1);
	stack[0] = 0;
	temp = arr[a - 1];
	while (i < a)
	{
		stack[i] = arr[i - 1];
		i++;
	}
	stack[i] = temp;
	free(arr);
	return (stack);
}

void	pa(t_list *main)
{
	main->alen++;
	main->stacka = swipe_down(main->stacka, main->alen);
	main->stacka[0] = main->stackb[0];
	main->blen--;
	swipe_up(main->stackb, main->blen);
	ft_printf("pa\n");
}

void	ra(t_list *main)
{
	int	temp;

	temp = main->stacka[0];
	swipe_up(main->stacka, main->alen);
	main->stacka[main->alen - 1] = temp;
	ft_printf("ra\n");
}

void	rra(t_list *main)
{
	int	temp;

	temp = main->stacka[main->alen - 1];
	main->stacka = swipe_down(main->stacka, main->alen);
	main->stacka[0] = temp;
	ft_printf("rra\n");
}

void	sa(t_list *main)
{
	int	temp;

	temp = main->stacka[0];
	main->stacka[0] = main->stacka[1];
	main->stacka[1] = temp;
	ft_printf("sa\n");
}
