/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:43:06 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/10 18:44:13 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ft_listlen(t_stack **a)
{
	t_stack	*temp;
	int		i;

	temp = *a;
	i = 1;
	while (temp->next != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

char	**normalizer(char **av)
{
	int		i;
	int		j;
	char	**new;

	new = malloc(sizeof(char *) * (ft_len(av)));
	if (!new)
		return (NULL);
	i = 1;
	j = 0;
	while (av[i])
	{
		new[j] = av[i];
		i++;
		j++;
	}
	new[j] = NULL;
	return (new);
}

int	is_sort(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	go_end_node(t_stack **list)
{
	t_stack	*tmp;

	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
}
