/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:44:11 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 00:16:23 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swipe_up(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
}

void	pb(t_list *main)
{
	main->blen++;
	main->stackb = swipe_down(main->stackb, main->blen);
	main->stackb[0] = main->stacka[0];
	main->alen--;
	swipe_up(main->stacka, main->alen);
	ft_printf("pb\n");
}

void	rb(t_list *main)
{
	int	temp;

	temp = main->stackb[0];
	swipe_up(main->stackb, main->blen);
	main->stackb[main->alen - 1] = temp;
	ft_printf("rb\n");
}

void	rrb(t_list *main)
{
	int	temp;

	temp = main->stackb[main->blen - 1];
	main->stackb = swipe_down(main->stackb, main->blen);
	main->stackb[0] = temp;
	ft_printf("rrb\n");
}

void	sb(t_list *main)
{
	int	temp;

	temp = main->stackb[0];
	main->stackb[0] = main->stackb[1];
	main->stackb[1] = temp;
	ft_printf("sb\n");
}
