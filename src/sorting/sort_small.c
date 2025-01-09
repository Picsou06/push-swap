/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:16:57 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 22:49:06 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_small_stack(t_list *a)
{
	sort_list(a);
	if (a->nb_elem == 2)
		sa(a);
	else if (a->nb_elem == 3)
		sort_three(a, 0, 1, 2);
	else if (a->nb_elem == 4)
		sort_four(a);
	else if (a->nb_elem == 5)
		sort_five(a);
}
