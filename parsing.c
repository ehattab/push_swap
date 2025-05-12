/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:05:40 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/12 16:45:51 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char **av, char *target, int index)
{
	int	i;
	int	current_num;
	int	target_num;

	target_num = ft_atoi(target);
	i = 0;
	while (av[i])
	{
		if (i != index)
		{
			current_num = ft_atoi(av[i]);
			if (current_num == target_num)
				return (1);
		}
		i++;
	}
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	check_all(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (is_number(av[i]) == 1)
		{
			free(av);
			ft_error("Error\n");
		}
		if (check_duplicate(av, av[i], i) == 1)
		{
			free(av);
			ft_error("Error\n");
		}
		if (ft_long_atoi(av[i]) > INT_MAX || ft_long_atoi(av[i]) < INT_MIN)
		{
			free(av);
			ft_error("Error\n");
		}
		i++;
	}
}

// int main(int ac, char **av)
// {
//     char    **av2;

//     if (ac == 2)
//     {
//         av2 = ft_split(av[1], 32);
//         av = av2;
//     }
//     if (ac < 2)
//         ft_error("Error\n");
//     if (ac == 2)
//         check_all(av);
//     else
//         check_all(av + 1);
//     t_stack *a;
//     a = NULL;
//     add_arg(&a, av);
//     part2(a);
//     return (0);
// }
