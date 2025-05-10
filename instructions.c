/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:15:01 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/10 18:15:10 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = (*a)->value;
	(*a)->value = tmp->next->value;
	tmp->next->value = i;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *b;
	i = (*b)->value;
	(*b)->value = tmp->next->value;
	tmp->next->value = i;
	ft_printf("sb\n");
}

void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	*a = (*a)->next;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	first = *b;
	last = *b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	*b = (*b)->next;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*last;

	first = *a;
	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*a = last;
	ft_printf("rra\n");
}
