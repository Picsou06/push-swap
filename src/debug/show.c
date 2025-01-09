/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picsou06 <picsou06@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:01:41 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 20:19:30 by picsou06         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	show_list(t_list *list)
{
	t_element	*elem;

	elem = list->first;
	while (elem)
	{
		printf("%d\n", elem->nbr);
		elem = elem->next;
	}
}
