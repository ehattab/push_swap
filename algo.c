/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:18:42 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/12 16:55:37 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && third > second && first < third)
		sa(a);
	else if (first < second && second > third && third < second)
		rra(a);
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first > second && first > third && second > third)
	{
		ra(a);
		sa(a);
	}
	else if (first < second && second > third && third > first)
	{
		rra(a);
		sa(a);
	}
}

void	small_sort4(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;
	int		count;

	tmp = *a;
	last = ft_lstend(a);
	count = ft_listlen(a);
	while (count--)
	{
		if (last->index == 0)
		{
			rra(a);
			break ;
		}
		if (tmp->index == 0)
		{
			break ;
		}
		ra(a);
		tmp = *a;
	}
	pb(a, b);
	small_sort3(a);
	pa(a, b);
}

void	found_first(t_stack **a, t_stack **b, unsigned int i)
{
	t_stack	*tmp;
	t_stack	*last;
	int		count;

	tmp = *a;
	last = ft_lstend(a);
	count = ft_listlen(a);
	while (count--)
	{
		if (last->index == i)
		{
			rra(a);
			pb(a, b);
			break ;
		}
		if (tmp->index == i)
		{
			pb(a, b);
			break ;
		}
		ra(a);
		tmp = *a;
	}
}

void	small_sort5(t_stack **a, t_stack **b)
{
	found_first(a, b, 0);
	found_first(a, b, 1);
	small_sort3(a);
	pa(a, b);
	pa(a, b);
}

void	big_sort_radix(t_stack **a, t_stack **b, t_struct *t)
{
	int	tmp;
	int	i;
	int	j;

	i = -1;
	t->k = 0;
	t->len = ft_listlen(a);
	max_bit_len(t);
	while (++i < t->bitslen)
	{
		j = -1;
		while (++j < t->len)
		{
			tmp = (*a)->index;
			t->mask = 1 << i;
			t->k = (tmp & t->mask);
			if (t->k == 0)
				pb(a, b);
			else
				ra(a);
		}
		while ((*b) != NULL)
			pa(a, b);
	}
}

// void	max_bit_len(t_struct *t)
// {
// 	t->bitslen = 0;
// 	while ((t->len - 1) >> t->bitslen != 0)
// 		t->bitslen++;
// }