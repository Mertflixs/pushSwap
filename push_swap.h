/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:46:07 by malasaha          #+#    #+#             */
/*   Updated: 2022/06/20 13:01:39 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

typedef struct s_list
{
	char	**split;
	int		*stacka;
	int		*stackb;
	int		*sort_a;
	int		*index;
	int		alen;
	int		blen;
	int		fake_alen;
	int		maxbits;
}			t_list;

//main
void		setup(t_list *main);
void		ft_exit(t_list *main, int flag);
//utils
void		*swipe_down(int *arr, int a);
void		swipe_up(int *stack, int len);
void		pa(t_list *main);
void		pb(t_list *main);
void		ra(t_list *main);
void		rb(t_list *main);
void		rra(t_list *main);
void		rrb(t_list *main);
void		sa(t_list *main);
void		sb(t_list *main);
void		rr(t_list *main);
void		ss(t_list	*main);
void		rrr(t_list *main);
//is_digit
int			is_digit_2(char *arr, t_list *main);
int			is_digit(char **arr, t_list *main);
//ft_sort
void		radix_sort(t_list *main);
int			max_bit(t_list *main);
int			find_index(t_list *main, int a);
void		threesort(t_list *main);
void		fivesort(t_list *main);
//ft_atoi
int			ft_atoi(const char *str, t_list *main);
//ft_split
char		**ft_split(char const *s, char c);
//checker
int			is_double(t_list *main);
int			is_sorted(t_list *main);
void		ft_sort(t_list *main);
void		create(t_list *main, int ac, char **av);
void		check(t_list *main, int ac, char **av);
//ft_printf
int			ft_printf(const char *s, ...);

#endif