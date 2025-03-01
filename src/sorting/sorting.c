/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:51:04 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 22:51:27 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	compare_and_swap(t_list *a, t_element *el1, t_element *el2)
{
	int	i;

	i = 0;
	while (i < a->nb_elem - 1)
	{
		while (el2 != NULL)
		{
			if (el2->nbr < el1->nbr)
			{
				swap_element(el1, el2);
				el2 = el2->next;
			}
			else
				el2 = el2->next;
		}
		i++;
		el1 = el1->next;
		el2 = el1->next;
	}
}

t_list	*sort_list(t_list *a)
{
	t_list		*copy;
	t_element	*el1;
	t_element	*el2;

	copy = copy_list(a);
	el1 = copy->first;
	el2 = copy->first->next;
	compare_and_swap(a, el1, el2);
	attribute_order(a, copy);
	free_all_list(copy);
	return (a);
}
