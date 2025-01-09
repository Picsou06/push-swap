/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:16:38 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 22:50:38 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	top_is_second(t_list *a, t_list *b)
{
	pb(a, b);
	sort_three(a, 0, 2, 3);
	pa(b, a);
	sa(a);
}

static void	top_is_third(t_list *a, t_list *b)
{
	sa(a);
	free_all_list(b);
	sort_four(a);
}

void	sort_four(t_list *a)
{
	t_list		*b;

	b = init_list(-1);
	if (a->first->nbr == 0)
	{
		pb(a, b);
		sort_three(a, 1, 2, 3);
		pa(b, a);
	}
	else if (a->first->nbr == 1)
		top_is_second(a, b);
	else if (a->first->nbr == 2)
		top_is_third(a, b);
	else if (a->first->nbr == 3)
	{
		pb(a, b);
		sort_three(a, 0, 1, 2);
		pa(b, a);
		ra(a);
	}
	free_all_list(b);
}
