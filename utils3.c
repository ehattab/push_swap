/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:28:20 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/10 18:18:39 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_in_tab(int *tab)
{
	int	tmp;
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] > tab[i + 1] && tab[i + 1] != '\0')
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (tab);
}

void	ft_give_index(int *tab, t_stack **a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		i = 0;
		while (tab[i])
		{
			if (tmp->value == tab[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	print_tab(int *tableau)
{
	int	i;

	i = 0;
	while (tableau[i])
	{
		ft_printf("%d\n", tableau[i]);
		i++;
	}
	ft_printf("\n");
}

void	ft_lst_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_stack	*ft_lstend(t_stack **lst)
{
	t_stack	*tmp;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
