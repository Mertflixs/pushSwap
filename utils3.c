/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:53:18 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 13:00:08 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list *main)
{
	int	temp;

	temp = main->stacka[0];
	swipe_up(main->stacka, main->alen);
	main->stacka[main->alen - 1] = temp;
	temp = main->stackb[0];
	swipe_up(main->stackb, main->blen);
	main->stackb[main->blen - 1] = temp;
	ft_printf("rr\n");
}

void	ss(t_list	*main)
{
	int	temp;

	temp = main->stacka[0];
	main->stacka[0] = main->stacka[1];
	main->stacka[1] = temp;
	temp = main->stackb[0];
	main->stackb[0] = main->stackb[1];
	main->stackb[1] = temp;
	ft_printf("ss\n");
}

void	rrr(t_list *main)
{
	int	temp;

	temp = main->stacka[main->alen - 1];
	main->stacka = swipe_down(main->stacka, main->alen);
	main->stacka[0] = temp;
	temp = main->stackb[main->blen - 1];
	main->stackb = swipe_down(main->stackb, main->blen);
	main->stackb[0] = temp;
	ft_printf("rrr\n");
}
