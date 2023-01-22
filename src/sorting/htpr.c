/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htpr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:12:36 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/01/20 16:59:30 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stk, int val)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = stk;
	while (ptr)
	{
		if (ptr->index == val)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (-1);
}

int	get_dis(t_stack *ptr, int index)
{
	if (index < ft_stklen(ptr) - index)
		return (index);
	return (ft_stklen(ptr) - index);
}

void	push_two_top(t_stack **a, t_stack **b, int *index)
{
	push_top(b, *index - 1);
	pa(a, b, 1);
	push_top(b, *index);
	(*index)--;
	pa(a, b, 1);
	sa(a, 1);
}

void	push_top(t_stack **stk, int index)
{
	int		i;
	int		len;

	len = ft_stklen(*stk);
	i = find_index(*stk, index);
	if (i <= len - i)
		while (i--)
			rb(stk, 1);
	else
	{
		i = len - i;
		while (i--)
			rrb(stk, 1);
	}
}
