/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:17:05 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/10 00:23:08 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	mid_insertion(t_list *list, t_element *element, int nw_nbr)
{
	t_element	*actuel;
	t_element	*new;

	new = malloc(sizeof(*new));
	if (list == NULL || new == NULL)
	{
		return (1);
	}
	actuel = list->first;
	while (actuel != element)
		actuel = actuel->next;
	if (actuel == element)
	{
		new->nbr = nw_nbr;
		new->next = actuel->next;
		actuel->next = new;
		list->nb_elem++;
	}
	else
		return (0);
	return (0);
}

t_list	*init_list(int nbr)
{
	t_element	*element;
	t_list		*list;

	list = malloc(sizeof(*list));
	element = malloc(sizeof(*element));
	if (list == NULL || element == NULL)
	{
		return (NULL);
	}
	element->nbr = nbr;
	element->next = NULL;
	list->first = element;
	list->nb_elem = 1;

	return (list);
}

int	insert_list(t_list *list, int nbr)
{
	t_element	*new;

	new = malloc(sizeof(*new));
	if (list == NULL || new == NULL)
	{
		return (1);
	}
	new->nbr = nbr;
	new->next = list->first;
	list->first = new;
	list->nb_elem++;
	return (0);
}
