/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarbaoui <aarbaoui@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:14:32 by aarbaoui          #+#    #+#             */
/*   Updated: 2023/01/12 18:22:02 by aarbaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_init(t_stack **a, t_stack **b, int d)
{
	int	size;
	int	max;
	int	chunk;

	size = ft_stklen(*a);
	chunk = size / d;
	max = chunk;
	while (1)
	{
		push_chunks(a, b, chunk, max);
		if (!ft_stklen(*a))
			break ;
		max += chunk;
	}
	sort_chunks(a, b);
}

void	push_chunks(t_stack **a, t_stack **b, int chunk, int max)
{
	int	i;
	int	half;

	half = chunk / 2;
	i = 0;
	while (*a && i < chunk)
	{
		if ((*a)->index <= max)
		{
			if ((*a)->index <= max - half)
				pb(a, b, 1);
			else
			{
				pb(a, b, 1);
				rb(b, 1);
			}
			i++;
		}
		else
			ra(a, 1);
	}
}

void	sort_chunks(t_stack **a, t_stack **b)
{
	int	index;
	int	fbig;
	int	sbig;

	index = ft_stklen(*b);
	while (index > 0)
	{
		index--;
		fbig = find_index(*b, index);
		sbig = find_index(*b, index - 1);
		if (index == 0 || get_dis(*b, fbig) < get_dis(*b, sbig))
		{
			push_top(b, index);
			pa(a, b, 1);
		}
		else
			push_two_top(a, b, &index);
	}
}
