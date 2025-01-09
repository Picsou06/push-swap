/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:17:26 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/10 00:30:35 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;

	if (ac < 2)
	{
		ft_printf("Usage: %s <numbers>\n", av[0]);
		return (1);
	}
	a = ft_parse(ac, av);
	show_list(a);
	if (!a)
	{
		ft_printf("Error: Invalid input\n");
		return (1);
	}
	if (a_is_sorted(a))
	{
		free_all_list(a);
		return (0);
	}
	if (a->nb_elem <= 5)
		sort_small_stack(a);
	else
		sort_big_stack(a);
	free_all_list(a);
	return (0);
}
