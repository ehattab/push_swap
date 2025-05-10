/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:32:23 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/10 18:19:08 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*last;

	first = *b;
	tmp = *b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*b = last;
	ft_printf("rrb\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	ft_printf("pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	ft_printf("pa\n");
}
