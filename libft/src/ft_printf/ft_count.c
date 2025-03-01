/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:54:40 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/09 22:26:24 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_nb_len(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_unsignednb_len(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}
