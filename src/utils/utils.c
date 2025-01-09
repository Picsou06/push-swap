/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:24:29 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 23:22:24 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	free_all_list(t_list *list)
{
	t_element	*to_del;

	if (list == NULL)
		return (1);
	to_del = list->first;
	while (list->first != NULL)
	{
		list->first = list->first->next;
		free(to_del);
		to_del = list->first;
	}
	free(list);
	list = NULL;
	return (0);
}

void	show_list(t_list *list)
{
	t_element	*elem;

	elem = list->first;
	while (elem)
	{
		ft_printf("%d\n", elem->nbr);
		elem = elem->next;
	}
}

t_list	*copy_list(t_list *a)
{
	t_list		*copy;
	t_element	*to_cpy;
	t_element	*index;

	if (a == NULL)
	{
		return (NULL);
	}
	copy = init_list(a->first->nbr);
	index = copy->first;
	to_cpy = a->first->next;
	while (to_cpy != NULL)
	{
		mid_insertion(copy, index, to_cpy->nbr);
		index = index->next;
		to_cpy = to_cpy->next;
	}
	copy->nb_elem = a->nb_elem;
	return (copy);
}
