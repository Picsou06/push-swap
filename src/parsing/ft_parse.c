/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: picsou06 <picsou06@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:01:41 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 20:23:26 by picsou06         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ft_isvalid(char *str, int ac, char **av)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (!check_duplicate(ac, av) || !chech_digit_overflow(ac, av))
		return (0);
	return (1);
}

static int	check_duplicate(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	chech_digit_overflow(int ac, char **av)
{
	int		i;
	long	nbr;

	i = 1;
	while (i < ac)
	{
		nbr = ft_atoi(av[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

t_list	*ft_parse(int ac, char **av)
{
	t_list		*list;
	t_element	*elem;
	int			i;

	i = 1;
	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->first = NULL;
	list->nb_elem = 0;
	while (i < ac)
	{
		if (!ft_isvalid(av[i], ac, av))
			return (NULL);
		elem = malloc(sizeof(t_element));
		if (!elem)
			return (NULL);
		elem->nbr = ft_atoi(av[i]);
		elem->pos = i++;
		elem->next = list->first;
		list->first = elem;
		list->nb_elem++;
	}
	return (list);
}
