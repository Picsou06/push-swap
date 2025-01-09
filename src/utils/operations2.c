/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:39:59 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/10 00:20:24 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_list *a)
{
	t_element	*temp;
	t_element	*temp2;

	ft_printf("ra\n");
	temp = a->first;
	a->first = a->first->next;
	temp->next = NULL;
	temp2 = a->first;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
}

void	rb(t_list *b)
{
	t_element	*temp;
	t_element	*temp2;

	ft_printf("rb\n");
	temp = b->first;
	b->first = b->first->next;
	temp->next = NULL;
	temp2 = b->first;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
}

void	rr(t_list *a, t_list *b)
{
	ft_printf("rr\n");
	ra(a);
	rb(b);
}

void	rra(t_list *a)
{
	t_element	*temp2;
	t_element	*temp;

	ft_printf("rra\n");
	temp2 = a->first;
	while (temp2->next->next != NULL)
		temp2 = temp2->next;
	temp = temp2->next;
	temp2->next = NULL;
	temp->next = a->first;
	a->first = temp;
}

void	rrb(t_list *b)
{
	t_element	*temp;
	t_element	*temp2;

	ft_printf("rrb\n");
	temp = b->first;
	temp2 = b->first;
	while (temp2->next->next != NULL)
		temp2 = temp2->next;
	b->first = temp2->next;
	temp2->next = NULL;
	b->first->next = temp;
}
