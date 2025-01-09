/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:17:15 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/10 00:20:02 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_list *a)
{
	t_element	*temp;

	ft_printf("sa\n");
	temp = a->first;
	a->first = a->first->next;
	temp->next = a->first->next;
	a->first->next = temp;
}

void	sb(t_list *b)
{
	t_element	*temp;

	ft_printf("sb\n");
	temp = b->first;
	b->first = b->first->next;
	temp->next = b->first->next;
	b->first->next = temp;
}

void	ss(t_list *a, t_list *b)
{
	ft_printf("ss\n");
	sa(a);
	sb(b);
}

void	pa(t_list *a, t_list *b)
{
	t_element	*temp;

	ft_printf("pa\n");
	temp = a->first;
	a->first = a->first->next;
	temp->next = b->first;
	b->first = temp;
	b->nb_elem--;
	a->nb_elem++;
}

void	pb(t_list *a, t_list *b)
{
	t_element	*temp;

	ft_printf("pb\n");
	temp = a->first;
	a->first = a->first->next;
	temp->next = b->first;
	b->first = temp;
	a->nb_elem--;
	b->nb_elem++;
}
