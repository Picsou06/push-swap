/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:12:40 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 18:58:27 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
    t_list *list;

    if (ac < 2)
    {
        ft_printf("Usage: %s <numbers>\n", av[0]);
        ft_printf("Example: %s 4 67 3 87\n", av[0]);
        return (1);
    }

    list = ft_parse(ac, av);
    if (!list)
    {
        ft_printf("Error: Invalid input\n");
        return (1);
    }

    show_list(list);
    return (0);
}