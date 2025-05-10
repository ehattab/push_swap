/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehattab <ehattab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:05:44 by ehattab           #+#    #+#             */
/*   Updated: 2025/05/10 18:50:27 by ehattab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "libft/Header/libft.h"
# include "libft/Header/ft_printf.h"

typedef struct s_stack
{
	unsigned int	index;
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_struct
{
	int		len;
	int		bitslen;
	int		k;
	int		mask;
}	t_struct;

void	ft_error(char *s);
int		is_number(char *str);
int		check_duplicate(char **av, char *target, int index);
void	check_all(char **av);
void	ft_end_node(t_stack **head, int arg);
int		*add_arg(t_stack **head, char **av);
long	ft_long_atoi(const char *str);
void	part2(int *tab, t_stack *a);
void	print_stack(t_stack *a, t_stack *b);
char	**normalizer(char **av);
int		is_sort(t_stack *a);
int		ft_listlen(t_stack **a);
void	go_end_node(t_stack **list);
int		*ft_sort_in_tab(int *tab);
int		ft_len(char **av);
void	ft_give_index(int *tab, t_stack **a);
void	print_tab(int *tableau);
void	ft_lst_free(t_stack **lst);
t_stack	*ft_lstend(t_stack **lst);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rb(t_stack **b);
void	ra(t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	small_sort3(t_stack **a);
void	small_sort4(t_stack **a, t_stack **b);
void	found_first(t_stack **a, t_stack **b, unsigned int i);
void	small_sort5(t_stack **a, t_stack **b);
void	ned(t_struct *t);
void	radix(t_stack **a, t_stack **b, t_struct *t);

#endif