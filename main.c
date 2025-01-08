/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:12:40 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 18:42:17 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int main(int ac, char **av)
{
    t_list *list;

    if (ac < 2)
    {
        printf("Usage: %s <numbers>\n", av[0]);
        return (1);
    }

    list = ft_parse(ac, av);
    if (!list)
    {
        printf("Error: Invalid input\n");
        return (1);
    }

    show_list(list);
    return (0);
}