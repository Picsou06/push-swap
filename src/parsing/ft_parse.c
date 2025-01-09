/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:17:33 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/10 00:47:24 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	char	*endptr;

	i = 1;
	while (i < ac)
	{
		errno = 0;
		nbr = ft_strtol(av[i], &endptr, 10);
		if (errno == ERANGE || nbr > INT_MAX || nbr < INT_MIN)
		{
			return (0);
		}
		if (*endptr != '\0')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_isvalid(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_duplicate(ac, av) || !chech_digit_overflow(ac, av))
		return (0);
	return (1);
}

t_list	*ft_parse(int ac, char **av)
{
	t_list		*list;
	int			i;

	if (!ft_isvalid(ac, av))
		return (NULL);
	i = ac - 1;
	list = init_list(ft_atoi(av[i--]));
	if (!list)
		return (NULL);
	while (i > 0)
	{
		insert_list(list, ft_atoi(av[i--]));
	}
	return (list);
}
