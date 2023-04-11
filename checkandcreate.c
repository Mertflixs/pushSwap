/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkandcreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:28:11 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/21 16:17:44 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_double(t_list *main)
{
	int	i;
	int	j;

	i = 0;
	while (i < main->alen)
	{
		j = 0;
		while (j < main->alen)
		{
			if (main->stacka[i] == main->stacka[j] && j != i)
				ft_exit(main, 1);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_list *main)
{
	int	i;

	i = 0;
	while (i < main->alen)
	{
		if (i + 1 < main->alen && main->stacka[i] > main->stacka[i + 1])
			return (1);
		i++;
	}
	ft_exit(main, 0);
	return (0);
}

void	ft_sort(t_list *main)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < main->alen)
	{
		j = 0;
		while (j < main->alen)
		{
			if (main->sort_a[i] < main->sort_a[j])
			{
				temp = main->sort_a[i];
				main->sort_a[i] = main->sort_a[j];
				main->sort_a[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	create(t_list *main, int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		main->split = ft_split(av[i], ' ');
		j = 0;
		while (main->split[j])
		{
			main->sort_a[k] = ft_atoi(main->split[j], main);
			main->stacka[k] = main->sort_a[k];
			free(main->split[j]);
			j++;
			k++;
		}
		if (main->split)
			free(main->split);
		i++;
	}
	is_double(main);
	is_sorted(main);
	ft_sort(main);
}

void	check(t_list *main, int ac, char **av)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 1;
	while (i < ac)
	{
		main->split = ft_split(av[i], ' ');
		if (is_digit(main->split, main) == 0)
			ft_exit(main, 2);
		j = 0;
		while (main->split[j] != NULL)
		{
			free(main->split[j]);
			j++;
			len++;
		}
		if (main->split)
			free(main->split);
		i++;
	}
	main->alen = len;
	main->fake_alen = len;
}
