/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:01:41 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 18:59:12 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int ft_isvalid(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

t_list *ft_parse(int ac, char **av)
{
    t_list *list;
    t_element *elem;
    int i;

    list = NULL;
    i = 1;
    list = malloc(sizeof(t_list));
    if (!list)
        return (NULL);
    list->first = NULL;
    list->nb_elem = 0;
    while (i < ac)
    {
        if (!ft_isvalid(av[i]))
            return (NULL);
        elem = malloc(sizeof(t_element));
        if (!elem)
            return (NULL);
        elem->nbr = ft_atoi(av[i]);
        elem->pos = i;
        elem->next = list->first;
        list->first = elem;
        list->nb_elem++;
        i++;
    }
    return (list);
}