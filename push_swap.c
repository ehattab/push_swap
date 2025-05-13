/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:06:21 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/13 14:31:07 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack **a, t_stack **b, int *tab, t_struct *t)
{
	ft_lst_free(a);
	ft_lst_free(b);
	free(tab);
	free(t);
}

int	main(int ac, char **av)
{
	int		*tab;
	t_stack	*a;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		av = ft_split2(av[1], 32);
		check_all(av);
	}
	else
	{
		av = normalizer(av); 
		check_all2(av);
	}
	a = NULL;
	tab = add_arg(&a, av);
	if (ac == 2)
		ft_free_tab(av);
	else
		free(av);
	part2(tab, a);
	return (0);
}

void	part2(int *tab, t_stack *a)
{
	t_stack		*b;
	t_struct	*t;

	t = malloc(sizeof(t_struct));
	b = NULL;
	tab = ft_sort_in_tab(tab);
	ft_give_index(tab, &a);
	if (is_sort(a) && ft_listlen(&a) == 2)
		sa(&a);
	else if (is_sort(a) && ft_listlen(&a) == 3)
		small_sort3(&a);
	else if (is_sort(a) && ft_listlen(&a) == 4)
		small_sort4(&a, &b);
	else if (is_sort(a) && ft_listlen(&a) == 5)
		small_sort5(&a, &b);
	else if (is_sort(a) && ft_listlen(&a) > 5)
		big_sort_radix(&a, &b, t);
	free_all(&a, &b, tab, t);
	return ;
}

	// print_stack(a, b);