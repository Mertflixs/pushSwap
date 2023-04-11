/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:48:40 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/21 16:59:31 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup(t_list *main)
{
	main->stacka = malloc(sizeof(int) * main->alen);
	main->stackb = malloc(sizeof(int) * main->alen);
	main->sort_a = malloc(sizeof(int) * main->alen);
	main->blen = 0;
}

void	ft_exit(t_list *main, int flag)
{
	int	i;

	i = 0;
	if (main->stacka)
		free(main->stacka);
	if (main->stackb)
		free(main->stackb);
	if (main->sort_a)
		free(main->sort_a);
	if (flag == 2)
	{
		while (main->split[i])
			free(main->split[i++]);
		if (main->split)
			free(main->split);
	}
	if (flag != 0)
		write(2, "Error\n", 6);
	free(main);
	exit(1);
}

int	main(int ac, char **av)
{
	t_list	*main;

	if (ac >= 2)
	{
		main = malloc(sizeof(t_list));
		check(main, ac, av);
		setup(main);
		create(main, ac, av);
		if (main->alen == 5)
			fivesort(main);
		else if (main->alen == 3)
			threesort(main);
		else if (main->alen == 2)
			sa(main);
		else
			radix_sort(main);
		ft_exit(main, 0);
	}
	return (0);
}
