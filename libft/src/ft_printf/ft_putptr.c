/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdalmas <evdalmas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:49:16 by evdalmas          #+#    #+#             */
/*   Updated: 2025/01/08 17:03:03 by evdalmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	if (num == 0)
		return (3);
	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putptr(void *ptr)
{
	if ((unsigned long)ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return ;
	}
	ft_putstr_fd("0x", 1);
	ft_puthex((unsigned long)ptr);
}
