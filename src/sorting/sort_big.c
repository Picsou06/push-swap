/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:16:28 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 22:50:24 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	empty_b(t_list *a, t_list *b)
{
	while (b->first->nbr != -1)
	{
		pa(b, a);
		b->nb_elem--;
		a->nb_elem++;
	}
}

static void	push_last_bit_one(t_list *a, t_list *b, int size, int bit_max)
{
	int		i;
	int		nbr;

	i = 0;
	while (i < size)
	{
		nbr = a->first->nbr;
		if (((nbr >> bit_max) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	sort_big_stack(t_list *a)
{
	t_list		*b;
	int			size;
	int			max_num;
	int			bit_max;

	b = init_list(-1);
	size = a->nb_elem;
	max_num = size - 1;
	bit_max = 0;
	sort_list(a);
	while (max_num >> bit_max != 0)
	{
		push_last_bit_one(a, b, size, bit_max);
		empty_b(a, b);
		bit_max++;
	}
	free_all_list(b);
}
