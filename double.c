/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:29:11 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/10 16:05:11 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_printf("ss");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}

// void	ned(t_struct *t)
// {
// 	t->bitslen = 0;
// 	while ((t->len - 1) >> t->bitslen != 0)
// 		t->bitslen++;
// }