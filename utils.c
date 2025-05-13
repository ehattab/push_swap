/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:32:39 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/13 14:17:46 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	ft_printf("%s", s);
	exit(1);
}

void	ft_end_node(t_stack **head, int arg)
{
	t_stack	*tmp;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error("Error\n");
	new->value = arg;
	new->next = NULL;
	if (!(*head))
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int	*add_arg(t_stack **head, char **av)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * (ft_len(av) + 1));
	if (!tab)
		return (NULL);
	while (av[i])
	{
		ft_end_node(head, ft_atoi(av[i]));
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

long	ft_long_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	print_stack(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = a;
	tmp2 = b;
	ft_printf("A       B\n");
	while (tmp || tmp2)
	{
		if (tmp)
			ft_printf("%d", tmp->value);
		else
			ft_printf(" ");
		ft_printf("       ");
		if (tmp2)
			ft_printf("%d", tmp2->value);
		else
			ft_printf(" ");
		ft_printf("\n");
		if (tmp)
			tmp = tmp->next;
		if (tmp2)
			tmp2 = tmp2->next;
	}
}
